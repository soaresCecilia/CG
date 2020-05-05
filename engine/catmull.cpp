#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/catmull.h"
#include <vector>
#include <cmath>
#define T_INCREMENT	0.0001



void Catmull::addTime(float t) {
    this->time = abs(t);
}
Catmull::Catmull() : Operation(nullptr) {
    float t[3] = {0, 1, 0};
    setYY(t);
}
Catmull::~Catmull() {}


void Catmull::addPoint(Point* p) {
    this->allPoints.push_back(p);
}

void buildRotMatrix(float* x, float* y, float* z, float* m) {

    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}

void cross(float* a, float* b, float* res) {

    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(float* a) {

    float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0] / l;
    a[1] = a[1] / l;
    a[2] = a[2] / l;
}


void multMatrixVector(float* m, float* v, float* res) {
    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }
}



void Catmull::setYY(float y[3]) {
    this->yy[0] = y[0];
    this->yy[1] = y[1];
    this->yy[2] = y[2];
}


Point Catmull::getCatmullPoint(float t, Point p0, Point p1, Point p2, Point p3, float* deriv) {
    float pp0[3] = { p0.getX(), p0.getY(), p0.getZ() };
    float pp1[3] = { p1.getX(), p1.getY(), p1.getZ() };
    float pp2[3] = { p2.getX(), p2.getY(), p2.getZ() };
    float pp3[3] = { p3.getX(), p3.getY(), p3.getZ() };
    float ppos[3];
    // catmull-rom matrix
    float m[4][4] = { {-0.5f,  1.5f, -1.5f,  0.5f},
                    { 1.0f, -2.5f,  2.0f, -0.5f},
                    {-0.5f,  0.0f,  0.5f,  0.0f},
                    { 0.0f,  1.0f,  0.0f,  0.0f}
    };
    // Compute A = M * P
    float A[3][4];

    for (int i = 0; i < 3; i++) {
        float v[4] = { pp0[i], pp1[i], pp2[i], pp3[i] };
        multMatrixVector(m[0], v, A[i]);
    }

    // Compute pos = T * A
    float T[4] = { t * t * t, t * t, t, 1 };

    for (int i = 0; i < 3; i++) {
        float v[4] = { A[i][0], A[i][1], A[i][2], A[i][3] };
        ppos[i] = T[0] * v[0] + T[1] * v[1] + T[2] * v[2] + T[3] * v[3];
    }

    // compute deriv = T' * A
    float TT[4] = {3 * t * t, 2 * t, 1, 0 };

    for (int i=0; i < 3; i++) {
        float v[4] = { A[i][0], A[i][1], A[i][2], A[i][3] };
        deriv[i] = TT[0] * v[0] + TT[1] * v[1] + TT[2] * v[2] + TT[3] * v[3];
    }

    return Point(ppos[0], ppos[1], ppos[2]);
}

// given  global t, returns the point in the curve
Point Catmull::getGlobalCatmullPoint(float globalT, float* deriv) {

    int nPoints = (this->allPoints.size());
    float t =  globalT * nPoints; // this is the real global t
    int index = floor(t);  // which segment

    t = t - index; // where within  the segment
    // indices store the points
    int indices[4];
    indices[0] = (index + nPoints - 1) % nPoints;
    indices[1] = (indices[0] + 1) % nPoints;
    indices[2] = (indices[1] + 1) % nPoints;
    indices[3] = (indices[2] + 1) % nPoints;
    return getCatmullPoint(t, *this->allPoints[indices[0]], *this->allPoints[indices[1]], *this->allPoints[indices[2]], *this->allPoints[indices[3]], deriv);
}

void Catmull::renderCatmull() {
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);

    for (float globalT=0; globalT < 1 ; globalT+=0.01f) {
        
        float deriv[3];
        Point pos = this->getGlobalCatmullPoint(globalT, deriv);
        glVertex3f(pos.getX(), pos.getY(), pos.getZ());
    }

    glEnd();

}

void Catmull::transform() {
    renderCatmull();
    float deriv[3];
    float tt = glutGet(GLUT_ELAPSED_TIME) / this->time ;
    Point pos = this->getGlobalCatmullPoint(tt, deriv);
    glTranslatef(pos.getX(), pos.getY(), pos.getZ());

        float zr[3];
        cross(deriv, this->yy, zr);
        float ty[3];
        cross(zr, deriv, ty);
        normalize(zr);
        normalize(deriv);
        normalize(ty);
        setYY(ty);
        float m[16];
        buildRotMatrix(deriv, ty, zr, m);
        glMultMatrixf(m);
   
}

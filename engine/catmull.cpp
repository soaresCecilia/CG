#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/catmull.h"
#include <vector>
#define T_INCREMENT	0.0001

void Catmull::addTime(float t) {
    this->time = abs(t);
}
Catmull::Catmull() {}
Catmull::~Catmull() {}

void Catmull::addPoint(Point* p) {
    this->contP.push_back(p);
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

Point Catmull::getCatmullRomPoint(float t, Point p0, Point p1, Point p2, Point p3, float* deriv) {
    float pp0[3]{ p0.getX(), p0.getY(), p0.getZ() };
    float pp1[3]{ p1.getX(), p1.getY(), p1.getZ() };
    float pp2[3]{ p2.getX(), p2.getY(), p2.getZ() };
    float pp3[3]{ p3.getX(), p3.getY(), p3.getZ() };
    float ppos[3];
    // catmull-rom matrix
    float m[4][4]{ {-0.5f,  1.5f, -1.5f,  0.5f},
                    { 1.0f, -2.5f,  2.0f, -0.5f},
                    {-0.5f,  0.0f,  0.5f,  0.0f},
                    { 0.0f,  1.0f,  0.0f,  0.0f}
    };
    // Compute A = M * P
    float A[3][4];

    for (int i{ 0 }; i < 3; i++) {
        float v[4]{ pp0[i], pp1[i], pp2[i], pp3[i] };
        multMatrixVector(m[0], v, A[i]);
    }

    // Compute pos = T * A
    float T[4]{ t * t * t, t * t, t, 1 };

    for (int i{ 0 }; i < 3; i++) {
        float v[4]{ A[i][0], A[i][1], A[i][2], A[i][3] };
        ppos[i] = T[0] * v[0] + T[1] * v[1] + T[2] * v[2] + T[3] * v[3];
    }

    // compute deriv = T' * A
    float TT[4]{ 3 * t * t, 2 * t, 1, 0 };

    for (int i{ 0 }; i < 3; i++) {
        float v[4]{ A[i][0], A[i][1], A[i][2], A[i][3] };
        deriv[i] = TT[0] * v[0] + TT[1] * v[1] + TT[2] * v[2] + TT[3] * v[3];
    }

    return Point(ppos[0], ppos[1], ppos[2]);
}

// given  global t, returns the point in the curve
Point Catmull::getGlobalCatmullRomPoint(float gt, float* deriv) {
    int nP{ (this->contP.size()) };
    float t{ gt * nP }; // this is the real global t
    int index{ (floor(t)) };  // which segment
    t = t - index; // where within  the segment
    // indices store the points
    int indices[4];
    indices[0] = (index + nP - 1) % nP;
    indices[1] = (indices[0] + 1) % nP;
    indices[2] = (indices[1] + 1) % nP;
    indices[3] = (indices[2] + 1) % nP;
    return getCatmullRomPoint(t, *this->contP[indices[0]], *this->contP[indices[1]], *this->contP[indices[2]], *this->contP[indices[3]], deriv);
}

void Catmull::renderCatmullRomCurve() {
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);

    for (float gt=0; gt < 1 ; gt+=0.01f) {
        
        float deriv[3];
        Point pos{ this->getGlobalCatmullRomPoint(gt, deriv) };
        glVertex3f(pos.getX(), pos.getY(), pos.getZ());
    }

    glEnd();

}

void Catmull::draw() {
    renderCatmullRomCurve();
    float deriv[3];
    float tt{ glutGet(GLUT_ELAPSED_TIME) / this->time };
    Point pos{ this->getGlobalCatmullRomPoint(tt, deriv) };
    glTranslatef(pos.getX(), pos.getY(), pos.getZ());

        float zr[3];
        cross(deriv, this->yAxis, zr);
        float ty[3];
        cross(zr, deriv, ty);
        normalize(zr);
        normalize(deriv);
        normalize(ty);
        this->setYAxis(ty);
        float m[16];
        buildRotMatrix(deriv, ty, zr, m);
        glMultMatrixf(m);
   
}
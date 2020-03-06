
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/FormaGeo.h"

#define _USE_MATH_DEFINES
#include <math.h>


//em que é que consiste uma forma geometrica
FormaGeo::FormaGeo(int n) {
        this->nPoints = n;
}

FormaGeo::~FormaGeo() {
}

void FormaGeo::addVertexPoint(Point *p) {
        (this->vertexPoint.push_back(p));
}

size_t FormaGeo::getNPoint(){
    return (this->nPoints);
}

std::vector<Point *>* FormaGeo::getVector() {
    return &(this->vertexPoint);
}


/*
void FormaGeo::fillBuffer() {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    
    float radius = 1;
    float height = 2;
    int slices = 10;

    const size_t vertexes_size = (slices * 3 + slices * 6 + slices * 3) * 3;
    float* vertexes = (float*)malloc(sizeof(float) * vertexes_size);
    int vi = 0;
    const float step = (2 * M_PI) / slices;
    float alpha = 0.0;
    float rgb = 1.0 / slices;
    const float base = -1 * height / 2.0;
    const float top_base = base + height;
    for (int i = 0; i < slices; i++) {
        const float dstep = alpha + step;
        const float a[3] = { radius * sin(dstep), base, radius * cos(dstep) };
        const float b[3] = { 0.0, base, 0.0 };
        const float c[3] = { radius * sin(alpha), base, radius * cos(alpha) };
        const float al[3] = { radius * sin(dstep), top_base, radius * cos(dstep) };
        const float bl[3] = { 0.0, top_base, 0.0 };
        const float cl[3] = { radius * sin(alpha), top_base, radius * cos(alpha) };
        const size_t v_size = sizeof(float) * 3;
        //base
        memcpy(vertexes + vi, c, v_size);
        vi += 3;
        memcpy(vertexes + vi, b, v_size);
        vi += 3;
        memcpy(vertexes + vi, a, v_size);
        vi += 3;
        //base'
        memcpy(vertexes + vi, al, v_size);
        vi += 3;
        memcpy(vertexes + vi, bl, v_size);
        vi += 3;
        memcpy(vertexes + vi, cl, v_size);
        vi += 3;
        //side
        memcpy(vertexes + vi, a, v_size);
        vi += 3;
        memcpy(vertexes + vi, al, v_size);
        vi += 3;
        memcpy(vertexes + vi, c, v_size);
        vi += 3;
        //side
        memcpy(vertexes + vi, c, v_size);
        vi += 3;
        memcpy(vertexes + vi, al, v_size);
        vi += 3;
        memcpy(vertexes + vi, cl, v_size);
        vi += 3;
        alpha += step;
        rgb += 1.0 / slices;
    }
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexes_size, vertexes, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    free(vertexes);
}


void FormaGeo::draw() {
    
    //specifies the location and data of an array of vertex coordinates to use when rendering
    int slices = 10;
    int n = slices * 3 + slices * 6 + slices * 3;
    glDrawArrays(GL_TRIANGLES, 0, n);
}
*/


void FormaGeo::fillBuffer() {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    const size_t n = this->nPoints * 3;
    float *vertexes =  (float *) malloc(sizeof(float) * n);
    int new_vertex = 0;
    
    
    for (auto &point : this->vertexPoint) {
        vertexes[new_vertex++] = point->getX();
        vertexes[new_vertex++] = point->getY();
        vertexes[new_vertex++] = point->getZ();
        
        
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * n , vertexes, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    
    free(vertexes);
}

void FormaGeo::draw() {
    GLsizei n = this->nPoints;
    glDrawArrays(GL_TRIANGLES, 0, n);
}

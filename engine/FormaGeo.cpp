
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

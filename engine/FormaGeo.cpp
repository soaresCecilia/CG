
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


void FormaGeo::buffering() {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    size_t allpoints = 0;
    
    int pointsForm = this->getNPoint();
    allpoints = pointsForm * 3;
    
    
    float *vertexes =  (float *) malloc(sizeof(float) * allpoints);
    
    int new_vertex = 0;
    
    for (auto &point : vertexPoint) {
        vertexes[new_vertex++] = point->getX();
        vertexes[new_vertex++] = point->getY();
        vertexes[new_vertex++] = point->getZ();
    }
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * allpoints , vertexes, GL_STATIC_DRAW);
    
    free(vertexes);
    
    
}


void FormaGeo::draw() {
    int pointsForm = this->getNPoint();
    size_t allpoints = pointsForm * 3;
    
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    
    glVertexPointer(3, GL_FLOAT, 0, 0);
    
    
    glDrawArrays(GL_TRIANGLES, 0, allpoints);
    
}



#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/FormaGeo.h"


//em que é que consiste uma forma geometrica
FormaGeo::FormaGeo(int n) {
        this->nPoints = n;
}

FormaGeo::~FormaGeo() {
}

void FormaGeo::addVertexPoint(Point *p) {
        this->vertexPoint.push_back(p);
}

int FormaGeo::getNPoint(){
    return this->nPoints;
}

std::vector<Point *>* FormaGeo::getVector() {
    return &(this->vertexPoint);
}


void FormaGeo::fillBuffer() {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    int n = this->nPoints * 3;
    float *vertexes =  new float[n];
    int nv = 0;
    
    for (auto &point : this->vertexPoint) {
        vertexes[nv++] = point->getX();
        vertexes[nv++] = point->getY();
        vertexes[nv++] = point->getZ();
    }
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * n, vertexes, GL_STATIC_DRAW);
    

    free(vertexes);
}

void FormaGeo::draw() {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, this->nPoints * 3);
    
}

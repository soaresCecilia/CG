/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
*/

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


void FormaGeo::draw() {

}

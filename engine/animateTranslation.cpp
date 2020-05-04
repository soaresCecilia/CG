#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/animateTranslation.h"
#include <vector>


void animateTranslation::addCoordinates(const Point& p) {
    this->coordinates.push_back(p.getX());
    this->coordinates.push_back(p.getY());
    this->coordinates.push_back(p.getZ());
}

void animateTranslation::addTime(float t) {
    time = t;
}

animateTranslation::animateTranslation() {}



animateTranslation::~animateTranslation() {}

void animateTranslation::transform() {
   
}

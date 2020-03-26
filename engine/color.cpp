//
//  color.cpp
//  
//
//  Created by Cecilia Soares on 26/03/2020.
//
#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif


#include "../headers/color.h"


Color::Color(Point *p) : Operation(p) {}

Color::~Color() {}

void Color::transform() {
    Point *p = getPoint();
    glColor3f(p->getX(), p->getY(), p->getZ());
}

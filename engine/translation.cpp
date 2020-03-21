//
//  translation.cpp
//  
//
//  Created by Cecilia Soares on 15/03/2020.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/translation.h"

Translation::Translation(Point *p) : Operation(p) {}

Translation::~Translation() {}

void Translation::transform() {
    Point *p = getPoint();
    glTranslatef(p->getX(), p->getY(), p->getZ());
}

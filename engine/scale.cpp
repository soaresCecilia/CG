
#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/scale.h"

Scale::Scale(Point* p) : Operation(p) {}

Scale::~Scale() {}

void Scale::transform() {
	Point* p = getPoint();
	glScalef(p->getX(), p->getY(), p->getZ());
}



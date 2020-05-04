#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/animateRotation.h"

animateRotation::animateRotation(Point* p, float a) : Operation(p), angle(a) {}

animateRotation::~animateRotation() {}

void animateRotation::transform() {
	Point* p = getPoint();
	glRotatef(this->angle, p->getX(), p->getY(), p->getZ());
}

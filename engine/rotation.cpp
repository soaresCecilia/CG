
#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/rotation.h"

Rotation::Rotation(Point *p, float a) : Operation(p), angle(a) {}

Rotation::~Rotation() {}

void Rotation::transform() {
	Point* p = getPoint();
	glRotatef(this->angle, p->getX(), p->getY(), p->getZ());
}


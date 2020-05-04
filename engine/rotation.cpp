#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/rotation.h"

Rotation::Rotation(Point *p, float angle, float time) : Operation(p), angle(angle), time(time) {}

Rotation::~Rotation() {}

void Rotation::transform() {
    angle = (time == 0 ? angle : glutGet(GLUT_ELAPSED_TIME) * 360 / time);
    
	Point* p = getPoint();
	glRotatef(this->angle, p->getX(), p->getY(), p->getZ());
}


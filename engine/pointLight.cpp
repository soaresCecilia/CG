#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif


#include "../headers/pointLight.h"
#include "../headers/point.h"

PointLight::PointLight() : Lights() {}

void PointLight::draw() {
    Point p{ this->getPos() };
    float pos[4]{
            pos[0]=p.getX(), p.getY(), p.getZ(), 1.0f
    };
    glLightfv(GL_LIGHT0 + this->getIndex(), GL_POSITION, pos);
    glLightf(GL_LIGHT0 + this->getIndex(), GL_QUADRATIC_ATTENUATION, this->getQuad_att());
    //glLightfv(GL_LIGHT0 + this->INDEX(), GL_AMBIENT, this->AMB());
    //glLightfv(GL_LIGHT0 + this->INDEX(), GL_DIFFUSE, this->COLOR());
}
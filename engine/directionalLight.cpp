#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/directionalLight.h"
#include "../headers/point.h"

DirectionalLight::DirectionalLight() : Lights() {}

void DirectionalLight::draw() {
    Point p{ this->getPos() };
    float pos[4]{
            p.getX(), p.getY(), p.getZ(), 0.0f
    };
    glLightfv(GL_LIGHT0 + this->getIndex(), GL_POSITION, pos);
    //glLightfv(GL_LIGHT0 + this->INDEX(), GL_AMBIENT, this->AMB());
    //glLightfv(GL_LIGHT0 + this->INDEX(), GL_DIFFUSE, this->COLOR());
}
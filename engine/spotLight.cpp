#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/spotLight.h"
#include "../headers/point.h"

SpotLight::SpotLight() : Lights() {

    float defSpotDir[3]{ 0, 0, -1 };

    spotDir.setX(defSpotDir[0]);
    spotDir.setY(defSpotDir[0]);
    spotDir.setZ(defSpotDir[0]);

    this->cutOff = 45; // Default Values

    this->exp = 0;      // Default Values
}


void SpotLight::setSpotDirLight(float x, float y, float z) {
    spotDir.setX(x);
    spotDir.setX(y);
    spotDir.setX(z);
}

void SpotLight::setCutOff(float c) {
    this->cutOff = c;
}

void SpotLight::setExp(float ex) {
    this->exp = ex;
}

void SpotLight::draw() {
    Point p{ this->getPos() };
    Point sd{ this->getSpotDirLight() };
    float pos[4]{
            p.getX(), p.getY(), p.getZ(), 1.0f
    };
    float spotDir[3]{
            p.getX(), p.getY(), p.getZ()
    };
    glLightfv(GL_LIGHT0 + this->getIndex(), GL_POSITION, pos);
    //glLightfv(GL_LIGHT0 + this->INDEX(), GL_DIFFUSE, this->COLOR());
    glLightfv(GL_LIGHT0 + this->getIndex(), GL_SPOT_DIRECTION, spotDir);
    glLightf(GL_LIGHT0 + this->getIndex(), GL_SPOT_CUTOFF, this->cutOff);
    glLightf(GL_LIGHT0 + this->getIndex(), GL_SPOT_EXPONENT, this->exp);
}
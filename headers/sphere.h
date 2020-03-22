#ifndef __SPHERE_H__
#define __SPHERE_H__

/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
*/
#include "point.h"
#include <vector>


//em que é que consiste uma forma geometrica
class Sphere {
    private:
       float radius;
       int slices;
       int stacks;
       std::vector<Point *> points;

    public:
        Sphere(float radius, int slices, int stacks) {
            this->radius = radius;
            this->slices = slices;
            this->stacks = stacks;
        }
        void drawSphere();
        void sphereToFile(char*);
};

#endif

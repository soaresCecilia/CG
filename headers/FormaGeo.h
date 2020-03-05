#ifndef __FORMAGEO_H__
#define __FORMAGEO_H__

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
class FormaGeo {
    private:
        int nPoints;
        std::vector<Point *> vertexPoint;

    public:
        FormaGeo(int);
        ~FormaGeo();
        void addVertexPoint(Point *);
        void draw();
        int getNPoint();
        std::vector<Point *>* getVector();
};

#endif

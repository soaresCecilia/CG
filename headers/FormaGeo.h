#ifndef __FORMAGEO_H__
#define __FORMAGEO_H__


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "point.h"
#include <vector>

//em que é que consiste uma forma geometrica
class FormaGeo {
    private:
        size_t nPoints;
        std::vector<Point *> vertexPoint;

    public:
        GLuint buffer[1];
        FormaGeo(int);
        ~FormaGeo();
        void addVertexPoint(Point *);
        void draw();
        void fillBuffer();
        size_t getNPoint();
        std::vector<Point *>* getVector();
};

#endif

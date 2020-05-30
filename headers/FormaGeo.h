#ifndef __FORMAGEO_H__
#define __FORMAGEO_H__


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "point.h"
#include "translation.h"
#include <vector>

class FormaGeo {
    private:
        size_t nPoints;
        std::vector<float> coordinates;
        std::vector<float> ligthNormals;
        std::vector<float> verticesTexture;
        GLuint buffer[3]; // vertices,  ligth normals , texturas

    public:
        FormaGeo(int);
        ~FormaGeo();
        void addCoordinates(const Point &p);
        void addLigthNormals(const Point& p);
        void addVerticesTexture(const Point& p);
        size_t getNPoint();
        void draw();
        void buffering();
};


#endif

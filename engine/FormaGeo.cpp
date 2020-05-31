#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/FormaGeo.h"


#define _USE_MATH_DEFINES
#include <math.h>


FormaGeo::FormaGeo(int n) {
        this->nPoints = n;
     //   this->texture = new Texture();
}

FormaGeo::~FormaGeo() {
}

void FormaGeo::addCoordinates(const Point &p) {
    this->coordinates.push_back(p.getX());
    this->coordinates.push_back(p.getY());
    this->coordinates.push_back(p.getZ());
    
}

void FormaGeo::addLigthNormals(const Point& p) {
    this->ligthNormals.push_back(p.getXl());
    this->ligthNormals.push_back(p.getYl());
    this->ligthNormals.push_back(p.getZl());

}

void FormaGeo::addVerticesTexture(const Point& p) {
    this->verticesTexture.push_back(p.getTextureX());
    this->verticesTexture.push_back(p.getTextureY());

}
/*
void FormaGeo::addPointTexture(Point* p) {
    this->textPoints.push_back(p);
}
*/
size_t FormaGeo::getNPoint(){
    return (this->nPoints);
}


void FormaGeo::buffering() { // aka prepare
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    int allcoordinates = this->getNPoint() * 3;
    
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * allcoordinates , coordinates.data(), GL_STATIC_DRAW);
    
}


void FormaGeo::draw() {
    int allcoordinates  = this->getNPoint() * 3;
    
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, allcoordinates);
}


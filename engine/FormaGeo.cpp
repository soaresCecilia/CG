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


void FormaGeo::addTexture(Texture* p) {
    this->texture = p;
}

void FormaGeo::addVerticesTexture(const Point& p) {
    this->verticesTexture.push_back(p.getTextureX());
    this->verticesTexture.push_back(p.getTextureY());

}



size_t FormaGeo::getNPoint(){
    return (this->nPoints);
}


void FormaGeo::buffering() { // aka prepare

   
    glGenBuffers(3, this->buffer);

    // pontos
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    int allcoordinates = this->getNPoint() * 3;
    
    //normals
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[1]);
    int allnormals = this->getNPoint() * 3;

    //textura
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[2]);
    int allTexturePoints = this->getNPoint() * 2;

    
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * allcoordinates , coordinates.data(), GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * allnormals, ligthNormals.data(), GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * allTexturePoints, verticesTexture.data(), GL_STATIC_DRAW);
    
}


void FormaGeo::draw() {
    int allcoordinates  = this->getNPoint() * 3;
    int allnormals = this->getNPoint() * 3;
    int allallTexturePoints = this->getNPoint() * 2;
    this->texture->setup();
    
    glBindTexture(GL_TEXTURE_2D, this->texture->textBuffer);

    //points
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);    
    glVertexPointer(3, GL_FLOAT, 0, 0);
    //normals
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[1]);
    glNormalPointer(GL_FLOAT, 0, 0);
    //textur
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[2]);
    glTexCoordPointer(2, GL_FLOAT, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, allcoordinates);
    glBindTexture(GL_TEXTURE_2D, 0);

}


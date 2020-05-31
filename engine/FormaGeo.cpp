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

	glGenTextures(1, &this->texture->textBuffer);
	this->texture->loadImage();
	glGenBuffers(3, this->buffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
	int n{ (int)this->nPoints * 3 }; // 3 coords x y z
	float* v{ new float[n] };
	int i{ 0 };

	for (auto& p : this->coordinates) {
		v[i++] = p;
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (n), v, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, this->buffer[1]);
	v = new float[n];
	i = 0;

	for (auto& p : this->ligthNormals) {
		v[i++] = p;
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (n), v, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, this->buffer[2]);
	v = new float[n/3*2];
	i = 0;

	for (auto& p : this->verticesTexture) {
		v[i++] = p;
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) *(n/3 * 2), v, GL_STATIC_DRAW);

}


void FormaGeo::draw() {
  this->texture->setup();
        glBindTexture(GL_TEXTURE_2D, this->texture->textBuffer);
        // Vertex Buffer
        glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
        glVertexPointer(3, GL_FLOAT, 0, 0);
        // Normal Buffer
        glBindBuffer(GL_ARRAY_BUFFER, this->buffer[1]);
        glNormalPointer(GL_FLOAT, 0, 0);
        // Text Buffer
        glBindBuffer(GL_ARRAY_BUFFER, this->buffer[2]);
        glTexCoordPointer(2, GL_FLOAT, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, this->nPoints * 3);
        glBindTexture(GL_TEXTURE_2D, 0);

}


#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <IL/il.h>
#include "../headers/texture.h"
#include <string>
#include "../headers/material.h"

Texture::Texture() {
	this->filename = NULL;
	this->height = -1;
	this->width = -1;
	this->material = new Material();
}

Texture::~Texture() {}



void Texture::addFile(std::string file) {
	this->filename = new char[file.length() + 1];
	strcpy(this->filename, file.c_str());
}



void Texture::addMaterial(Material* m) {
	this->material = m;
}
void Texture::setup() {
	this->material->setup();
}


void Texture::loadImage() {
	if (this->filename != NULL) {
		unsigned int t, tw, th;
		unsigned char* texData;
		ilInit();
		ilGenImages(1, &t);
		ilBindImage(t);
		ilLoadImage((ILstring)this->filename);
		tw = ilGetInteger(IL_IMAGE_WIDTH);
		this->width = tw;
		th = ilGetInteger(IL_IMAGE_HEIGHT);
		this->height = th;
		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
		texData = ilGetData();
		glBindTexture(GL_TEXTURE_2D, this->textBuffer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

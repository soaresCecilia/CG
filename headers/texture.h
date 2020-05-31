
#ifndef texture_h
#define texture_h

#include <stdio.h>
#include <string>
#include "material.h"

class Texture {
private:
	char* filename;
	unsigned int width;
	unsigned int height;
	Material* material;
public:
	unsigned int textBuffer;
	Texture();
	~Texture();
	void addFile(std::string);
	void addMaterial(Material*);
	void setup();
	void loadImage();
};

#endif 

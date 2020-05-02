#ifndef __BEZIERPATCH_H__
#define __BEZIERPATCH_H__

#include <string>
#include <vector>
#include "../headers/point.h"

class BezierPatch{
	
private:
	char* patch;
	int tesselation;

public:
	BezierPatch(char* patch, int t) :
		patch(patch),tesselation(t) {}

	void generateCurve();
	void curveToFile(char*);
};


#endif
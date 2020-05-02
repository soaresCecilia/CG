#ifndef __BEZIERPATCH_H__
#define __BEZIERPATCH_H__

#include <string>
#include <vector>
#include "../headers/point.h"

class BezierPatch{
	
private:
	char* filename;
	int tesselation;

public:
	BezierPatch(char* patchPath, int t) :
		filename(patchPath),tesselation(t) {}

	void generateCurve();
	void curveToFile(char*);
};


#endif
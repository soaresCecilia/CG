#ifndef __BEZIERPATCH_H__
#define __BEZIERPATCH_H__

#include <string>
#include <vector>
#include "../headers/point.h"

class BezierPatch{
	
private:
	char* filenameIn;
	int tesselation;
	char* filenameOut;
	std::vector<Point*> points;


public:
	BezierPatch(char* patchPath, int t, char* outPath ) :
		filenameIn(patchPath),tesselation(t), filenameOut(outPath) {}

	void getTrianglesToDraw(int nPatches, int* indicesPatches, int* pontosControlo);
	void generateCurve();
	void curveToFile();
};


#endif
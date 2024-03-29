#ifndef __BEZIERPATCH_H__
#define __BEZIERPATCH_H__

#include <string>
#include <vector>
#include "../headers/point.h"
#include <string>

class BezierPatch{
	
private:
	std::string inputFile;
	int tesselation;
	std::string outputFile;
	std::vector<Point*> points;


public:
	BezierPatch(std::string patchPath, int t, std::string outPath ) :
		inputFile(patchPath),tesselation(t), outputFile(outPath) {}

	void getTrianglesToDraw(int nPatches, int** indicesPatches, int** pontosControlo);
	void generateCurve();
	void readInFile(int* nPatches, int*** indices, int* nPtsControl, float*** ptsControl);
	void curveToFile();
	int drawBezier( int* nPatches, int* nPtsControl, int*** indicesPatches, float*** ptsControl);
	void calcPoints2Write(float points[4][4][4]);
	void calcPoint(float points[4][4][4], float u, float v, int ts);
};


#endif
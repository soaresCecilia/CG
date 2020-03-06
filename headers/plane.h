#ifndef __PLANE_H__
#define __PLANE_H__

#include "point.h"
#include <vector>

//em que é que consiste uma forma geometrica
class Plane {
private:
	float dim;
	std::vector<Point*> points;

public:
	Plane(float dim) :
		dim(dim) {}
	void drawPlane();
	void planeToFile(char*);
};

#endif
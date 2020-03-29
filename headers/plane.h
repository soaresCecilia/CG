#ifndef __PLANE_H__
#define __PLANE_H__

#include "point.h"
#include <vector>

class Plane {
private:
	float dim;
	std::vector<Point *> points;

public:
	Plane(float dim) :
		dim(dim) {}
	void generatePlane();
	void planeToFile(char*);
};

#endif

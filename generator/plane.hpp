#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "point.h"
#include <vector>

//em que é que consiste uma forma geometrica
class Plane {
private:
	double dim;
	std::vector<Point*> points;

public:
	Plane(double dim) :
		dim(dim) {}
	void drawPlane();
	void planeToFile(char*);
};

#endif
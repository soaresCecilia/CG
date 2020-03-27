#ifndef __PLANE_H__
#define __PLANE_H__

#include "point.h"
#include <vector>

//em que é que consiste uma forma geometrica
class Plane {
private:
	float dim;
	std::vector<float> points;

public:
	Plane(float dim) :
		dim(dim) {}
	void generatePlane();
	void planeToFile(char*);
};

#endif

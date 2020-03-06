#ifndef __CONEE_H__
#define __CONE_H__

#include "point.h"
#include <vector>

//em que é que consiste uma forma geometrica
class Cone {
private:
	float radius;
	float height;
	int slices;
	int stacks;
	std::vector<Point*> points;

public:
	Cone(float radius,float height, int slices, int stacks) :
		radius(radius),height(height), slices(slices), stacks(stacks) {}
	void drawCone();
	void coneToFile(char*);
};

#endif
#ifndef __BOX_H__
#define __BOX_H__

#include "point.h"
#include <vector>


class Box {
private:
	float x;
	float y;
	float z;
	float div;
	std::vector<Point*> points;

public:
	Box(float x, float y, float z, int div) :
		x(x), y(y), z(z), div(div) {}
	void generateBox();
	void boxToFile(char*);
};

#endif


#ifndef rotation_h
#define rotation_h

#include <stdio.h>
#include "Operation.h"


class Rotation: public Operation {
private:
	float angle;
public:
	Rotation(Point* p,float a);
	~Rotation();
	void transform();
};

#endif /* rotation_h */

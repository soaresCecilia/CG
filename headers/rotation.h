
#ifndef rotation_h
#define rotation_h

#include <stdio.h>
#include "Operation.h"


class Rotation: public Operation {
private:
	float angle;
    float time;
public:
	Rotation(Point* p,float angle, float time);
	~Rotation();
	void transform();
};

#endif /* rotation_h */

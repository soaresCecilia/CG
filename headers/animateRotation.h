
#ifndef animateRotation_h
#define animateRotation_h

#include <stdio.h>
#include "Operation.h"


class animateRotation : public Operation {
private:
	float angle;
public:
	animateRotation(Point* p, float a);
	~animateRotation();
	void transform();
};

#endif /* animateRotation_h */

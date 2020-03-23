#ifndef scale_h
#define scale_h

#include <stdio.h>
#include "Operation.h"


class Scale : public Operation {
public:
	Scale(Point* p);
	~Scale();
	void transform();
};

#endif /* scale_h */

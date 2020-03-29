#ifndef Operation_h
#define Operation_h



#include <stdio.h>
#include "../headers/point.h"

class Operation {
private:
    Point* p;
public:
    Operation(Point *);
    virtual ~Operation();
    virtual void transform() = 0;
    Point* getPoint();
};
#endif /* Operation_h */

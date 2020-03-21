//
//  Operation.h
//  
//
//  Created by Cecilia Soares on 21/03/2020.
//

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
    virtual void transform() = 0; //função polimorfica
    Point* getPoint();
};
#endif /* Operation_h */

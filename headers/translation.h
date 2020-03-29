#ifndef translation_h
#define translation_h

#include <stdio.h>
#include "Operation.h"

class Translation: public Operation {
    public:
    Translation(Point *p);
    ~Translation();
    void transform();
};

#endif /* translation_h */

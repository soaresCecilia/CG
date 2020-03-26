//
//  color.h
//  
//
//  Created by Cecilia Soares on 26/03/2020.
//

#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include "Operation.h"

class Color: public Operation {
    public:
    Color(Point *p);
    ~Color();
    void transform();
};


#endif /* color_h */

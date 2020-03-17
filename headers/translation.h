//
//  translation.h
//  
//
//  Created by Cecilia Soares on 15/03/2020.
//

#ifndef translation_h
#define translation_h

#include <stdio.h>
#include "../headers/point.h"

class Translation{
    private:
    float x;
    float y;
    float z;
    
    public:
    Translation();
    Translation(Point p);
    ~Translation();
    float getX() const;
    float getY() const;
    float getZ() const;
};

#endif /* translation_h */



#ifndef LIGTHS_H
#define LIGTHS_H

#include <stdio.h>
#include "point.h"

class Lights {
    private:
        Point pos;
        float colour[4];
    
    public:
        Lights();
        ~Lights();
        Lights(Point *pos, float colour[4]);
        Point getPos() {
            return pos;
        }
        void setPointLight(float x, float y, float z);
    
        float* getColour() {
            return colour;
        }
        void setColour(float r, float g, float b, float a);
    
};



#endif /* lights_h */

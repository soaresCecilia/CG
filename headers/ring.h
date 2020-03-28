#ifndef __RING_H__
#define __RING_H__

#include "point.h"
#include <vector>


//em que é que consiste uma forma geometrica
class Ring {
    private:
       float radius;
       int slices;
       std::vector<Point *> points;

    public:
        Ring(float radius, int slices) {
            this->radius = radius;
            this->slices = slices;
        }
        void generateRing();
        void ringToFile(char*);
};

#endif
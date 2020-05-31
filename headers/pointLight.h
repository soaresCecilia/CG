
#ifndef __POINT_LIGHT_H__
#define __POINT_LIGHT_H__

#include "../headers/lights.h"

class PointLight : public Lights {

public:
    PointLight();
    ~PointLight();

    void draw();
};
#endif
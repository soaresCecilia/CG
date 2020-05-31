
#ifndef __DIRECTION_LIGHT_H__
#define __DIRECTION_LIGHT_H__


#include "../headers/lights.h"

class DirectionalLight : public Lights {

public:
    DirectionalLight();
    ~DirectionalLight();

    void draw();
};
#endif
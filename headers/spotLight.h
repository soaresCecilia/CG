
#ifndef __SPOT_LIGHT_H__
#define __SPOT_LIGHT_H__


#include "../headers/lights.h"

class SpotLight : public Lights {
private:
    Point spotDir;
    float cutOff;
    float exp;
public:
    SpotLight();
    ~SpotLight();

    
    Point getSpotDirLight() {
        return spotDir;
    }
  
    void setSpotDirLight(float x, float y, float z);

    void setCutOff(float);
    void setExp(float);
    void draw();
};

#endif
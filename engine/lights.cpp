
#include "../headers/lights.h"


Lights::Lights() {
    this->pos = Point(0,0,0);
    float colour[4] {1, 1, 1, 1};
}

Lights::~Lights() {}

Lights::Lights(Point *pos, float colour[4]) {
    this->pos.setX(pos->getX());
    this->pos.setY(pos->getY());
    this->pos.setZ(pos->getZ());
    
    for(int i = 0; i < 4; i++) {
        this->colour[i] = colour[i];
    }
}


void Lights::setPointLight(float x, float y, float z) {
    this->pos.setX(x);
    this->pos.setY(y);
    this->pos.setZ(z);
}

void Lights::setColour(float r, float g, float b, float a){
    this->colour[0] = r;
    this->colour[1] = g;
    this->colour[2] = b;
    this->colour[3] = a;

}

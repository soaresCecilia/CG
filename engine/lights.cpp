#include <stdlib.h>
#include "../headers/lights.h"


Lights::Lights() {
    this->i = -1;
}

Lights::~Lights() {}


void Lights::setIndex(int i) {
    this->i = i;
}

int Lights::getIndex() {
    return i;
}

//
//  translation.cpp
//  
//
//  Created by Cecilia Soares on 15/03/2020.
//

#include "../headers/translation.h"


Translation::Translation(): x(0.0f), y(0.0f), z(0.0f) {}

Translation::~Translation() {}

Translation::Translation(Point p) : x(p.getX()), y(p.getY()), z(p.getZ()) {}

float Translation::getX() const {
    return x;
}

float Translation::getY() const {
    return y;
}

float Translation::getZ() const {
    return z;
}

//
//  point.cpp
//  
//
//  Created by Cecilia Soares on 23/02/2020.
//

#include "point.h"

Point::Point(): x(0.0f), y(0.0f), z(0.0f) {}

Point::~Point() {} /* destroi um ponto criado */

Point::Point(float x, float y, float z) : x(x), y(y), z(z) {}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getZ() const {
    return z;
}

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << '(' << pt.getX() << ',' << pt.getY() << ',' << pt.getZ() << ')' << std::endl;
    return os;
}


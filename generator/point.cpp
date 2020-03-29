#include "../headers/point.h"

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

void Point::setX(float x) {
    this->x = x;
}
void Point::setY(float y) {
    this->y = y;
}
void Point::setZ(float z) {
    this->z = z;
}


std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << '(' << pt.getX() << ',' << pt.getY() << ',' << pt.getZ() << ')' << std::endl;
    return os;
}


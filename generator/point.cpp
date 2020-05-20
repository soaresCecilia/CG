#include "../headers/point.h"
#include <cmath>

Point::Point(): x(0.0f), y(0.0f), z(0.0f) {}

Point::~Point() {} /* destroi um ponto criado */

Point::Point(float x, float y, float z) : x(x), y(y), z(z) {}

Point::Point(float x, float y, float z, std::vector<float> normal, float textureX, float textureY)
: x(x) , y(y) , z(z) , normal(normal) , textureX(textureX) , textureY(textureY) {}


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

std::vector<float> Point::getNormal() const {
    return normal;
}

std::tuple<float, float> Point::getTexture() const {
    return std::make_tuple(this->textureX, this->textureY);
}

void Point::setTexture(float textureX, float textureY) {
    this->textureX = textureX;
    this->textureY = textureY;
}

void Point::setNormal(std::vector<float> n) {
    this->normal.assign(n.begin(), n.end());
}


Point Point::normalizeCoordPoint() {
    float componentX = getX();
    float componentY = getY();
    float componentZ = getZ();
    
    float length = sqrt(componentX * componentX + componentY * componentY + componentZ * componentZ);
    
    
    componentX = componentX / length;
    componentY = componentY / length;
    componentZ = componentZ / length;
    
    std::vector<float> normalized {componentX, componentY, componentZ};
    
    return Point(getX(), getY(), getZ(), normalized, 0, 0);
    
}


std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << '(' << pt.getX() << ',' << pt.getY() << ',' << pt.getZ() << ')' << std::endl;
    return os;
}


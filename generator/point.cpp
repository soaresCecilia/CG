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


float Point::getTextureX() const {
    return textureX;
}

float Point::getTextureY() const {
    return textureY;
}

void Point::setTexture(float textureX, float textureY) {
    this->textureX = textureX;
    this->textureY = textureY;
}

void Point::setNormal(std::vector<float> n) {
    this->normal.assign(n.begin(), n.end());
}


void Point::normalizeCoordPoint() {
    
    //This is the Euclidean norm, which gives the ordinary distance from the origin to a point
    float length = sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
    
    
    
    //O vetor normalizado - divide-se cada componente pela sua norma
    float componentX = getX() / length;
    float componentY = getY() / length;
    float componentZ = getZ() / length;
    
    std::vector<float> normalized {componentX, componentY, componentZ};
    
    setNormal(normalized);
 
    
}


/*
std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << '(' << pt.getX() << ' ' << pt.getY() << ' ' << pt.getZ() << ')' << ' ' << '(' << pt.getNormal().at(0) << ' ' << pt.getNormal().at(1) << ' ' << pt.getNormal().at(2) << ')' << ' ' << '(' << pt.getTextureX() << ' ' << pt.getTextureY() << ')' << std::endl;
    return os;
}



std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << '(' << pt.getX() << ',' << pt.getY() << ',' << pt.getZ() << ',' << pt.getNormal().at(0) << ',' << pt.getNormal().at(1) << ',' << pt.getNormal().at(2) << ',' << pt.getTextureX() << ',' << pt.getTextureY() << ')' << std::endl;
    return os;
}
*/


std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << pt.getX() << ' ' << pt.getY() << ' ' << pt.getZ() << ' ' << pt.getNormal().at(0) << ' ' << pt.getNormal().at(1) << ' ' << pt.getNormal().at(2) << ' ' << pt.getTextureX() << ' ' << pt.getTextureY() << std::endl;
    return os;
}

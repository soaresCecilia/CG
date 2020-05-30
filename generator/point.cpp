#include "../headers/point.h"
#include <cmath>

Point::Point(): x(0.0f), y(0.0f), z(0.0f) {}

Point::~Point() {} /* destroi um ponto criado */

Point::Point(float x, float y, float z) : x(x), y(y), z(z) {}

Point::Point(float x, float y, float z, float xl, float yl, float zl, float textureX, float textureY)
: x(x) , y(y) , z(z) , xl(xl), yl(yl), zl(zl), textureX(textureX) , textureY(textureY) {}


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






float Point::getXl() const {
    return xl;
}

float Point::getYl() const {
    return yl;
}

float Point::getZl() const {
    return zl;
}

void Point::setXl(float x) {
    this->xl = x;
}
void Point::setYl(float y) {
    this->yl = y;
}
void Point::setZl(float z) {
    this->zl = z;
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




void Point::normalizeCoordPoint() {
    
    //This is the Euclidean norm, which gives the ordinary distance from the origin to a point
    float length = sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
    
    
    
    //O vetor normalizado - divide-se cada componente pela sua norma
    float componentX = getX() / length;
    float componentY = getY() / length;
    float componentZ = getZ() / length;
    
    setXl(componentX);
    setYl(componentY);
    setZl(componentZ);
 
    
}



std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << '(' << pt.getX() << ',' << pt.getY() << ',' << pt.getZ() << ',' << pt.getXl() << ',' << pt.getYl() << ',' << pt.getZl()<< ',' << pt.getTextureX() << ',' << pt.getTextureY() << ')' << std::endl;
    return os;
}


/* para teste
std::ostream& operator<<(std::ostream& os, const Point& pt)
{
    os << pt.getX() << ',' << pt.getY() << ',' << pt.getZ() << std::endl << pt.getNormal().at(0) << ',' << pt.getNormal().at(1) << ',' << pt.getNormal().at(2) << std::endl << pt.getTextureX() << ',' << pt.getTextureY() << std::endl;
    return os;
}
*/

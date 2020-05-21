#ifndef point_h
#define point_h

#include <iostream>
#include <vector>

class Point{
private:
    float x;
    float y;
    float z;
    std::vector<float> normal;
    float textureX;
    float textureY;
    
public:
    Point();
    Point(float x, float y, float z);
    Point(float x, float y, float z, std::vector<float> normal, float textureX, float textureY);
    ~Point();
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    std::vector<float> getNormal() const;
    void setNormal(std::vector<float> normal);
    float getTextureX() const;
    float getTextureY() const;
    void setTexture(float textureX, float textureY);
    void normalizeCoordPoint();
    friend std::ostream& operator<<(std::ostream& os, const Point& dt);
};




#endif /* point_h */


#ifndef point_h
#define point_h

#include <iostream>
#include <vector>

class Point{
private:
    //points coordinates
    float x;
    float y;
    float z;

    // ligth normals coordinates
    float xl;
    float yl;
    float zl;

    // texture coordinates
    float textureX;
    float textureY;
    
public:
    Point();
    Point(float x, float y, float z);
    Point(float x, float y, float z, float xl, float yl, float zl, float textureX, float textureY);
    ~Point();
    
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
   
    float getXl() const;
    float getYl() const;
    float getZl() const;
    void setXl(float x);
    void setYl(float y);
    void setZl(float z);


    float getTextureX() const;
    float getTextureY() const;
    void setTexture(float textureX, float textureY);
    void normalizeCoordPoint();
    friend std::ostream& operator<<(std::ostream& os, const Point& dt);
};




#endif /* point_h */


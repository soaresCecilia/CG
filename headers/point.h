//
//  point.h
//  
//
//  Created by Cecilia Soares on 23/02/2020.
//

#ifndef point_h
#define point_h

#include <iostream>

class Point{
private:
    float x;
    float y;
    float z;
    
public:
    Point();
    Point(float x, float y, float z);
    ~Point();
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    friend std::ostream& operator<<(std::ostream& os, const Point& dt);
};




#endif /* point_h */


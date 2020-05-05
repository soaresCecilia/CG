#ifndef __CATMULL_H__
#define __CATMULL_H__

#include <vector>
#include "point.h"
#include "Operation.h"


class Catmull : public Operation {
private:
    std::vector<Point*> allPoints;
    float time;
    float yy[3];

public:
    Catmull();
    ~Catmull();
    void addTime(float);
    void addPoint(Point*);
    Point getCatmullPoint(float, Point, Point, Point, Point, float*);
    Point getGlobalCatmullPoint(float, float*);
    void renderCatmull();
    void setYY(float*);
    void transform();
};
#endif

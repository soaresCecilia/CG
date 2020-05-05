#ifndef __CATMULL_H__
#define __CATMULL_H__

#include <vector>
#include "point.h"
#include "Operation.h"


class Catmull : public Operation {
private:
    std::vector<Point*> contP;
    float time;
    float yAxis[3] = { 0,1,0 };

public:
    Catmull();
    ~Catmull();
    void addTime(float);
    void setYAxis(float*);
    void addPoint(Point*);
    Point getCatmullRomPoint(float, Point, Point, Point, Point, float*);
    Point getGlobalCatmullRomPoint(float, float*);
    void renderCatmullRomCurve();
    void draw();
    void transform();
};
#endif

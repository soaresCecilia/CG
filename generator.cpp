#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "point.h"



void plane(double dim, std::vector<Point *> *points) {
    

    //est‡ ainda a divis‹o inteira
    Point *c = new Point(-dim/2, 0.0f, dim/2); /*1.¼ e œltimo*/
    Point *b = new Point(dim/2, 0.0f, dim/2);
    Point *a = new Point(dim/2, 0.0f, -dim/2); /*2x seguidas*/
    Point *d = new Point(-dim/2, 0.0f, -dim/2);
    
    
    //push_back - Add element at the end of the vector
    points->push_back(c);
    points->push_back(b);
    points->push_back(a);
    points->push_back(a);
    points->push_back(d);
    points->push_back(c);
}


enum direction {
    up,
    down,
    left,
    right,
    front,
    back
};


std::vector<Point *> * genericPlane(float x, float y, float z, direction dir, std::vector<Point *> *points) {
    x = x/2;
    y = y/2;
    z = z/2;
    
    float heigth = 1;
    float depth = 1;
    float lateral = 1;
    
    
    switch (dir) {
        case up:
            heigth = -1;
            break;
        case down:
            y = -y;
            heigth = -1;
            break;
        case right:
            lateral = -1;
            break;
        case left:
            lateral = -1;
            x = -x;
            break;
        case front:
            depth = -1;
            break;
        case back:
            depth = -1;
            x = -x;
            z = -z;
            break;
    }
    
    
    
    Point *a = new Point(x, y, lateral * heigth * z);
    points->push_back(a);
    Point *b = new Point(depth * heigth * x, y, heigth * z);
    points->push_back(b);
    Point *c = new Point(depth * heigth * x, depth * lateral * y, z);
    points->push_back(c);
    Point *d = new Point(depth * heigth * x, depth * lateral * y, z);
    points->push_back(d);
    Point *e = new Point(x, depth * lateral * y, lateral * z);
    points->push_back(e);
    Point *f = new Point(x, y, lateral * heigth * z);
    points->push_back(f);
    
    
    return points;
    
    
    
}

void box(float x, float y, float z, std::vector<Point *> *points) {
    genericPlane(x,y,z,up,points);
    genericPlane(x,y,z,down,points);
    genericPlane(x,y,z,front,points);
    genericPlane(x,y,z,back,points);
    genericPlane(x,y,z,right,points);
    genericPlane(x,y,z,left,points);
}

void planeToFile(int dim, std::vector<Point *> *points, char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    plane(dim, points);
    
    int vectorLenght = points->size();
    
    myfile << vectorLenght << std::endl;
    for (int i=0; i < vectorLenght; i++){
        myfile << *(*points)[i];
    }
    
    
    myfile.close();
    
}



void boxToFile(double dimX, double dimY, double dimZ, std::vector<Point *> *points, char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    box(dimX, dimY, dimZ, points);
    
    int vectorLenght = points->size();
    
    myfile << vectorLenght << std::endl;
    for (int i=0; i < vectorLenght; i++){
        myfile << *(*points)[i];
    }
    
    
    myfile.close();
}



int main(int argc, char* argv[]) {
    
    std::vector<Point *> points;
    
    
    if (argc > 1 && !strcmp(argv[1], "plane")) {
        planeToFile(atoi(argv[2]), &points, argv[3]);
    }
    
    else if(argc > 1 && !strcmp(argv[1], "box")) {
        boxToFile(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), &points, argv[5]);
    }
    
	

	return 1;
}

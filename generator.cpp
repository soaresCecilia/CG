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
    points->push_back(d);
    points->push_back(a);
    points->push_back(a);
    points->push_back(b);
    points->push_back(c);
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






int main(int argc, char** argv) {
    
    std::vector<Point *> points;
    
    
    if (argc > 1 && !strcmp(argv[1], "plane")) {
        planeToFile(atoi(argv[2]), &points, argv[3]);
    }

	

	return 1;
}

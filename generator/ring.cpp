#include "../headers/ring.h"

#include <iostream>
#include <fstream>


#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

void Ring::generateRing(){

	float alpha = 0;
	float incremento = (2 * M_PI) / slices;


	float x1, z1;
	float x2, z2;
	float x3, z3;
	float x4, z4;


	for (int i = 0; i < slices; i++) {
		x1 = radius * sin(alpha);
		z1 = radius * cos(alpha);

		x2 = radius * sin(alpha + incremento);
		z2 = radius * cos(alpha + incremento);

		x3 = (radius*1.7) * sin(alpha);
		z3 = (radius*1.7) * cos(alpha);

		x4 = (radius*1.7) * sin(alpha + incremento);
		z4 = (radius*1.7) * cos(alpha + incremento);

	
			Point *a = new Point(x1,0,z1);
            points.push_back(a);
            
            Point *b = new Point(x3,0,z3);
            points.push_back(b);
            
            Point *c = new Point(x2,0,z2);
            points.push_back(c);
            
            Point *d = new Point(x2,0,z2);
            points.push_back(d);
            
            Point *e = new Point(x3,0,z3);
            points.push_back(e);
            
            Point *f = new Point(x4,0,z4);
            points.push_back(f);

			//sdown
			Point * g = new Point(x1, 0, z1);
			points.push_back(g);

			Point* h = new Point(x2, 0, z2);
			points.push_back(h);

			Point* m = new Point(x3, 0, z3);
			points.push_back(m);

			Point* j = new Point(x3, 0, z3);
			points.push_back(j);

			Point* k = new Point(x2, 0, z2);
			points.push_back(k);

			Point* l = new Point(x4, 0, z4);
			points.push_back(l);

		alpha += incremento;
	}

}

void Ring::ringToFile(char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    generateRing();
    
    int vectorLenght = this->points.size();
    
    myfile << vectorLenght << std::endl;
    for (int i=0; i < vectorLenght; i++){
        myfile << *(points[i]); 
    }
    
    myfile.close();
    
}
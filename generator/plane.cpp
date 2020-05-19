#include "../headers/plane.h"
#include <iostream>
#include <fstream>


void Plane::generatePlane() {
    
    std::vector<float> normalVector {0.0f, 1.0f, 0.0f};

    Point *c = new Point(-dim/2, 0.0f, dim/2, normalVector, 0, 1);
    Point *b = new Point(dim/2, 0.0f, dim/2, normalVector, 1, 1);
    Point *a = new Point(dim/2, 0.0f, -dim/2, normalVector, 1, 0);
    Point *d = new Point(-dim/2, 0.0f, -dim/2, normalVector, 0, 0);
    
    
    //push_back - Add element at the end of the vector
    points.push_back(a);
    
    points.push_back(d);
    
    points.push_back(c);

    points.push_back(c);
    
    points.push_back(b);
    
    points.push_back(a);
    
}

void Plane::planeToFile(char* filename) {

	std::ofstream myfile;
	myfile.open(filename);
	generatePlane();

	int vectorLenght = this->points.size();

	myfile << vectorLenght << std::endl;
	for (int i = 0; i < vectorLenght; i++) {
		myfile << *(points[i]);
	}

	myfile.close();

}

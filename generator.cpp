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


enum direction {
    up,
    down,
    left,
    right,
    front,
    back
};


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
            x = -x;
            heigth = -1;
            break;
        case right:
            lateral = -1;
            break;
        case left:
            lateral = -1;
            x = -x;
            z = -z;
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

void box(float dx, float dy, float dz, std::vector<Point *> *points) {
    
                genericPlane(dx,dy,dz,up,points);
                genericPlane(dx,dy,dz,down,points);
                genericPlane(dx,dy,dz,front,points);
                genericPlane(dx,dy,dz,back,points);
                genericPlane(dx,dy,dz,right,points);
                genericPlane(dx,dy,dz,left,points);
    
}


void drawSphere(float radius, int slices, int stacks, std::vector<Point *> *points) {
        
    float alpha = 0; // da a volta
    float teta = - (M_PI /2); // pendulo, cima, baixo
    float incrementoAlpha = (2 * M_PI) / slices;
    float incrementoTeta = M_PI / stacks;
    
    for (int i = 0; i < stacks; i++) {
        for (int j = 0; j < slices; j++) {
            
            // gera pontos
            // vertice A1
            float x1 = radius * cos(teta + incrementoTeta) * sin(alpha);
            float y1 = radius * sin(teta + incrementoTeta);
            float z1 = radius * cos(teta + incrementoTeta) * cos(alpha);
            
            // vertice A2
            float x2 = radius * cos(teta) * sin(alpha);
            float y2 = radius * sin(teta);
            float z2 = radius * cos(teta) * cos(alpha);
            
            // vertice A3
            float x3 = radius * cos(teta + incrementoTeta) * sin(alpha + incrementoAlpha);
            float y3 = radius * sin(teta + incrementoTeta);
            float z3 = radius * cos(teta + incrementoTeta) * cos(alpha + incrementoAlpha);
            
            // vertice A4
            float x4 = radius * cos(teta) * sin(alpha + incrementoAlpha);
            float y4 = radius * sin(teta);
            float z4 = radius * cos(teta) * cos(alpha + incrementoAlpha);
            
            
            
        
            // desenha um quadrado apenas
            // desenho triangulo baixo
            Point *a = new Point(x1,y1,z1);
            points->push_back(a);
            
            Point *b = new Point(x2,y2,z2);
            points->push_back(b);
            
            Point *c = new Point(x4,y4,z4);
            points->push_back(c);
            
            // desenho triangulo cima
            Point *d = new Point(x1,y1,z1);
            points->push_back(d);
            
            Point *e = new Point(x4,y4,z4);
            points->push_back(e);
            
            Point *f = new Point(x3,y3,z3);
            points->push_back(f);
            
            // incremento angulos
            alpha = alpha + incrementoAlpha;
        }
        teta = teta + incrementoTeta;
        
    }
    
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

void sphereToFile(float radius, int slices, int stacks, std::vector<Point *> *points, char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    drawSphere(radius, slices, stacks, points);
    
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
    
    else if(argc > 1 && !strcmp(argv[1], "sphere")) {
        sphereToFile(atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), &points, argv[6]);
    }
	

	return 0;
}

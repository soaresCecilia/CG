#include <stdlib.h> 
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


#define _USE_MATH_DEFINES
#include <math.h>


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


std::vector<Point *> * genericPlane(float x, float y, float z,int div, direction dir, std::vector<Point *> *points) {
	float div_increment_x = x / div;
	float div_increment_y = y / div;
	float div_increment_z = y / div;
	
	x = x/2;
    y = y/2;
    z = z/2;
    


    for(int i = 0;i<div;i++){
		for (int j = 0; j < div; j++) {
			//up
				Point* a = new Point(-x+(div_increment_x*i), y, -z+(div_increment_z*j)); //A
				points->push_back(a);
				Point* b = new Point(-x+(div_increment_x*i), y,-z+(div_increment_z*(j+1))); //B
				points->push_back(b);
				Point* c = new Point(-x + (div_increment_x * (i+1)), y, -z + (div_increment_z* j)); //C
				points->push_back(c);
				Point* d = new Point(-x + (div_increment_x * (i + 1)), y, -z + (div_increment_z * j)); //C
				points->push_back(d);
				Point* e = new Point(-x + (div_increment_x * i), y, -z + (div_increment_z * (j + 1))); //B
				points->push_back(e);
				Point* f = new Point(-x + (div_increment_x * (i+1)), y, -z + (div_increment_z * (j + 1))); //D
				points->push_back(f);
				
			// down
				Point* a2 = new Point(-x + (div_increment_x * i), -y, -z + (div_increment_z * j)); //A
				points->push_back(a2);
				Point* b2 = new Point(-x + (div_increment_x * (i + 1)), -y, -z + (div_increment_z * j)); //C
				points->push_back(b2);
				Point* c2 = new Point(-x + (div_increment_x * i),-y, -z + (div_increment_z * (j + 1))); //B
				points->push_back(c2);
				Point* d2 = new Point(-x + (div_increment_x * i), -y, -z + (div_increment_z * (j + 1))); //B
				points->push_back(d2);
				Point* e2 = new Point(-x + (div_increment_x * (i + 1)), -y, -z + (div_increment_z * j)); //C
				points->push_back(e2);
				Point* f2 = new Point(-x + (div_increment_x * (i + 1)), -y, -z + (div_increment_z * (j + 1))); //D
				points->push_back(f2);
				
			// right:
				Point* a3 = new Point(x, -y+(div_increment_y*i), -z + (div_increment_z * j)); //D
				points->push_back(a3);
				Point* b3 = new Point(x, -y+(div_increment_y*(i+1)), -z + (div_increment_z * j)); //C
				points->push_back(b3);
				Point* c3 = new Point(x, -y+(div_increment_y*i), -z + (div_increment_z * (j + 1))); //B
				points->push_back(c3);
				Point* d3 = new Point(x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
				points->push_back(d3);
				Point* e3 = new Point(x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
				points->push_back(e3);
				Point* f3 = new Point(x, -y+(div_increment_y*(i+1)), -z + (div_increment_z * (j + 1))); //A
				points->push_back(f3);
				
			// left
				Point* a4 = new Point(-x, -y + (div_increment_y * i), -z + (div_increment_z * j)); //D
				points->push_back(a4);
				Point* b4 = new Point(-x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
				points->push_back(b4);
				Point* c4 = new Point(-x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
				points->push_back(c4);
				Point* d4 = new Point(-x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
				points->push_back(d4);
				Point* e4 = new Point(-x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
				points->push_back(e4);
				Point* f4 = new Point(-x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * (j + 1))); //A
				points->push_back(f4);
				
			// front
				Point* a5 = new Point(-x+(div_increment_x*i), -y + (div_increment_y * i),z); //C
				points->push_back(a5);
				Point* b5 = new Point(-x+(div_increment_x*(i+1)), -y + (div_increment_y * i), z); //D
				points->push_back(b5);
				Point* c5 = new Point(-x+(div_increment_x*i), -y + (div_increment_y * (i + 1)),z); //A
				points->push_back(c5);
				Point* d5 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), z); //A
				points->push_back(d5);
				Point* e5 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), z); //D
				points->push_back(e5);
				Point* f5 = new Point(-x + (div_increment_y * (i + 1)), -y + (div_increment_z * (j + 1)),z); //B
				points->push_back(f5);
			
			// back
				Point* a6 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * i), -z); //C
				points->push_back(a6);
				Point* b6 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), -z); //A
				points->push_back(b6);
				Point* c6 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), -z); //D
				points->push_back(c6);
				Point* d6 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), -z); //D
				points->push_back(d6);
				Point* e6 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), -z); //A
				points->push_back(e6);
				Point* f6 = new Point(-x + (div_increment_y * (i + 1)), -y + (div_increment_z * (j + 1)), -z); //B
				points->push_back(f6);
				
		
			
		}
	}
    
    
    
    return points;
    
    
    
}

void box(float dx, float dy, float dz,int div, std::vector<Point *> *points) {
    
                genericPlane(dx,dy,dz,div,up,points);
              
    
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

void drawCone(float radius, float height, int slices, int stacks, std::vector<Point *> *points) {
	
	const float _alpha = (2 * M_PI) / slices;  //angulo de cada slice
	float alpha = 0.0;                         // angulo acumulativo a cada interacao

	float px_base;					           // ponto x a partir de um ponto e um angulo para base
	float pz_base;							   // ponto z a partir de um ponto e de um angulo para base		

	float px_base_ant = 0.0;                   // ponto anterior para saber o px
	float pz_base_ant = radius;                // ponto anterior para saber o pz

	float const _stack = height / stacks;      // a altura de cada stack
	float _stackIncrement = 0.0;

	float beta = atan(height / radius);        // angulo da inclinaçao do cone
	const float theta = radius / stacks; // valor do raio a cada stack, começando por cima


	float px;
	float pz;

	float px_ant = 0.0;
	float pz_ant = theta;


	for (int i = 0; i < stacks; i++) {
		for (int j = 0; j < slices; j++) {
			alpha = _alpha * (j + 1);

			px_base = radius * sin(alpha);
			pz_base = radius * cos(alpha);

			px = (radius - (theta * i)) * sin(_alpha * j);
			pz = (radius - (theta * i)) * cos(_alpha * j);


			if (!i) {
				// desenhar a base;

				float x4 = px_base_ant;
				float y4 = 0.0;
				float z4 = pz_base_ant;

				float x5 = 0.0;
				float y5 = 0.0;
				float z5 = 0.0;

				float x6 = px_base;
				float y6 = 0.0;
				float z6 = pz_base;
				
				Point* d = new Point(x4, y4, z4);
				points->push_back(d);

				Point* e = new Point(x5, y5, z5);
				points->push_back(e);


				Point* f = new Point(x6, y6, z6);
				points->push_back(f);
			}

			if (i == stacks - 1) {
				// desenhar a ultima stack, que é so um triangulo
				float x1 = 0.0;
				float y1 = height;
				float z1 = 0.0;

				float x2 = (radius - (theta * i)) * sin(_alpha * j);
				float y2 = i * _stack;
				float z2 = (radius - (theta * i)) * cos(_alpha * j);

				float x3 = (radius - (theta * i));
				float y3 = i * _stack;
				float z3 = (radius - (theta * i)) * cos(_alpha * (j + 1));

				Point* a = new Point(x1, y1, z1);
				points->push_back(a);

				Point* b = new Point(x2, y2, z2);
				points->push_back(b);


				Point* c = new Point(x3, y3, z3);
				points->push_back(c);
			}

			else {
				// desenhar a ultima stack, que é so um triangulo
				//A
				float x7 = (radius - (theta * i)) * sin(_alpha * j);
				float y7 = i * _stack;
				float z7 = (radius - (theta * i)) * cos(_alpha * j);
				//D
				float x8 = (radius - (theta * (i))) * sin(_alpha * (j + 1));
				float y8 = i * _stack;
				float z8 = (radius - (theta * (i))) * cos(_alpha * (j + 1));
				//c
				float x9 = (radius - (theta * (i + 1))) * sin(_alpha * (j + 1));
				float y9 = (i + 1) * _stack;
				float z9 = (radius - (theta * (i + 1))) * cos(_alpha * (j + 1));
				//c
				float x10 = (radius - (theta * (i + 1))) * sin(_alpha * (j + 1));
				float y10 = (i + 1) * _stack;
				float z10 = (radius - (theta * (i + 1))) * cos(_alpha * (j + 1));
				//B
				float x11 = (radius - (theta * (i + 1))) * sin(_alpha * (j + 1));
				float y11 = (i + 1) * _stack;
				float z11 = (radius - (theta * (i + 1))) * cos(_alpha * (j + 1));
				//A
				float x12 = (radius - (theta * i)) * sin(_alpha * j);
				float y12 = i * _stack;
				float z12 = (radius - (theta * i)) * cos(_alpha * j);
			

				Point* g = new Point(x7, y7, z7);
				points->push_back(g);

				
				Point* h = new Point(x8, y8, z8);
				points->push_back(h);

				Point* k = new Point(x9, y9, z9);
				points->push_back(k);
			
				Point* l = new Point(x10, y10, z10);
				points->push_back(l);

				Point* m = new Point(x11, y11, z11);
				points->push_back(l);

				Point* n = new Point(x12, y12, z12);
				points->push_back(l);


				// incremento angulos
				//alpha = alpha + incrementoAlpha;


			}

			px_ant = px;
			pz_ant = pz;


			px_base_ant = px_base;
			pz_base_ant = pz_base;
		}

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

void boxToFile(double dimX, double dimY, double dimZ,int div, std::vector<Point *> *points, char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    box(dimX, dimY, dimZ, div,points);
    
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

void coneToFile(float radius, float height, int slices, int stacks, std::vector<Point*>* points, char* filename) {
	std::ofstream myfile;
	myfile.open(filename);
	drawCone(radius,height,slices, stacks, points);

	int vectorLenght = points->size();

	myfile << vectorLenght << std::endl;
	for (int i = 0; i < vectorLenght; i++) {
		myfile << *(*points)[i];
	}

	myfile.close();
}

int main(int argc, char* argv[]) {
    
    std::vector<Point *> points;
    
    
    if (argc > 1 && !strcmp(argv[1], "plane")) {
        planeToFile(atoi(argv[2]), &points, argv[3]);
    }
    
    else if(argc == 7 && !strcmp(argv[1], "box")) {
        boxToFile(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), &points, argv[6]);
    }
    
    else if(argc == 6 && !strcmp(argv[1], "sphere")) {
        sphereToFile(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), &points, argv[5]);
    }
    
    else if(argc == 7 && !strcmp(argv[1], "cone")) {
        coneToFile(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), &points, argv[6]);
    }


	return 0;
}

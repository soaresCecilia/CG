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

void drawCone(float radius, float height, int slices, int stacks) {
	// code to draw the x,y,z 
	glBegin(GL_LINES);

	// X axis in red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);

	// Y Axis in Green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);

	// Z Axis in Blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -100.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();

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


	glBegin(GL_TRIANGLES);
	for (int i = 0; i < stacks; i++) {
		for (int j = 0; j < slices; j++) {
			alpha = _alpha * (j + 1);

			px_base = radius * sin(alpha);
			pz_base = radius * cos(alpha);

			px = (radius - (theta * i)) * sin(_alpha * j);
			pz = (radius - (theta * i)) * cos(_alpha * j);


			if (!i) {
				// desenhar a base; regra a partir da mao esquerda para nao ter angulo negativo

				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3f(px_base_ant, 0.0f, pz_base_ant);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(px_base, 0.0f, pz_base);

			}

			if (i == stacks - 1) {
				// desenhar a ultima stack, que é só um triangulo

				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3f(0.0f, height, 0.0f);
				glVertex3f((radius - (theta * i)) * sin(_alpha * j), i * _stack, (radius - (theta * i)) * cos(_alpha * j));
				glVertex3f((radius - (theta * i)) * sin(_alpha * (j + 1)), i * _stack, (radius - (theta * i)) * cos(_alpha * (j + 1)));

			}

			else {
				// desenhar a ultima stack, que é só um triangulo

				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3f((radius - (theta * i)) * sin(_alpha * j), i * _stack, (radius - (theta * i)) * cos(_alpha * j));//A
				glVertex3f((radius - (theta * (i))) * sin(_alpha * (j + 1)), i * _stack, (radius - (theta * (i))) * cos(_alpha * (j + 1)));//D
				glVertex3f((radius - (theta * (i + 1))) * sin(_alpha * (j + 1)), (i + 1) * _stack, (radius - (theta * (i + 1))) * cos(_alpha * (j + 1)));//c

				glVertex3f((radius - (theta * (i + 1))) * sin(_alpha * j), (i + 1) * _stack, (radius - (theta * (i + 1))) * cos(_alpha * j));//B
				glVertex3f((radius - (theta * i)) * sin(_alpha * j), i * _stack, (radius - (theta * i)) * cos(_alpha * j));//A
				glVertex3f((radius - (theta * (i + 1))) * sin(_alpha * (j + 1)), (i + 1) * _stack, (radius - (theta * (i + 1))) * cos(_alpha * (j + 1)));//C



			}

			px_ant = px;
			pz_ant = pz;


			px_base_ant = px_base;
			pz_base_ant = pz_base;
		}

	}
	glEnd();
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

void coneToFile(float radius, float height, int slices, int stacks, std::vector<Point*>* points, char* filename) {
	std::ofstream myfile;
	myfile.open(filename);
	drawCone(radius,height,slices, stacks);

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
    
    else if(argc > 1 && !strcmp(argv[1], "box")) {
        boxToFile(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), &points, argv[5]);
    }
    
    else if(argc > 1 && !strcmp(argv[1], "sphere")) {
        sphereToFile(atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), &points, argv[6]);
    }


	return 0;
}

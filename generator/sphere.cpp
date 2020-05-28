#include "../headers/sphere.h"

#include <iostream>
#include <fstream>


#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

void Sphere::generateSphere() {
        
    float alpha = 0; // da a volta
    float teta = - (M_PI /2); // pendulo, cima, baixo
    
    //PI * 2 because it is necessary to go all around to count all of the slices

    float incrementoAlpha = (2 * M_PI) / slices;
    
    //only PI because it is only necessary to go half the perimeter in the
    //vertical direction to count all of the stacks;
    float incrementoTeta = M_PI / stacks;
    
    
    //incremento das texturas

    
    std::vector<float> vector {0,0,0};
	float incrementoX = 1.0 / slices;
	float incrementoY = 1.0 / stacks;
	float textura_y ;
	float textura_x ;
	float textura_y_Next ;
	float textura_x_Next;
	int i, j;
	for ( i = 0; i < stacks; i++) { //y
        for ( j = 0; j < slices; j++) { //x

			textura_y = i * incrementoY;
			textura_x = j * incrementoX;
			textura_y_Next = (i+1) * incrementoY;
			textura_x_Next = (j+1) * incrementoX;

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
            Point *a = new Point(x1,y1,z1,vector,textura_x_Next,textura_y);
			a->normalizeCoordPoint();
            points.push_back(a);
            
            Point *b = new Point(x2,y2,z2, vector, textura_x,textura_y);
            b->normalizeCoordPoint();
            points.push_back(b);
            
            Point *c = new Point(x4,y4,z4, vector, textura_x,textura_y_Next);
            c->normalizeCoordPoint();
            points.push_back(c);
            
            // desenho triangulo cima
            //este ponto é igual ao a -> porque não pôr points.push_back(a)???;
         //   Point *d = new Point(x1,y1,z1, vector, textura_x, textura_y_Next);
           // d->normalizeCoordPoint();
            points.push_back(a);
            
            //Point *e = new Point(x4,y4,z4, vector, textura_x_Next, textura_y);
            //e->normalizeCoordPoint();
            points.push_back(c);
            
            Point *f = new Point(x3,y3,z3, vector, textura_x_Next, textura_y_Next);
            f->normalizeCoordPoint();
            points.push_back(f);
            
            // incremento angulos
            alpha = alpha + incrementoAlpha;
          
           
        }
        teta = teta + incrementoTeta;
       
        
    }
    
}

void Sphere::sphereToFile(char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    generateSphere();
    
    int vectorLenght = this->points.size();
    
    myfile << vectorLenght << std::endl;
    for (int i=0; i < vectorLenght; i++){
        myfile << *(points[i]); 
    }
    
    myfile.close();
    
}



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
    const float textureIncX = 1.0 / slices;
    const float textureIncY = 1.0 / stacks;
    float textureX = 0.0f;
    float textureY = 0.0f;
    
    std::vector<float> vector {0,0,0};
    
    for (int i = 0; i < stacks; i++) { //y
        for (int j = 0; j < slices; j++) { //x
        
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
            Point *a = new Point(x1,y1,z1,vector,textureX,textureY);
            a->normalizeCoordPoint();
            points.push_back(a);
            
            Point *b = new Point(x2,y2,z2, vector, textureX,textureY);
            b->normalizeCoordPoint();
            points.push_back(b);
            
            Point *c = new Point(x4,y4,z4, vector, textureX, textureY);
            c->normalizeCoordPoint();
            points.push_back(c);
            
            // desenho triangulo cima
            //este ponto é igual ao a -> porque não pôr points.push_back(a)???;
            Point *d = new Point(x1,y1,z1, vector, textureX,textureY);
            d->normalizeCoordPoint();
            points.push_back(d);
            
            Point *e = new Point(x4,y4,z4, vector, textureX, textureY);
            e->normalizeCoordPoint();
            points.push_back(e);
            
            Point *f = new Point(x3,y3,z3, vector, textureX, textureY);
            f->normalizeCoordPoint();
            points.push_back(f);
            
            // incremento angulos
            alpha = alpha + incrementoAlpha;
            textureX = j * textureIncX;
           
        }
        teta = teta + incrementoTeta;
        textureY = i * textureIncY;
        
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



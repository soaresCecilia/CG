#include "../headers/sphere.h"
#include "../headers/point.h"

void drawSphere() {
        
    float alpha = 0; // da a volta
    float teta = - (M_PI /2); // pendulo, cima, baixo
    float incrementoAlpha = (2 * M_PI) / slices;
    float incrementoTeta = M_PI / stacks;
    
    for (int i = 0; i < this->stacks; i++) {
        for (int j = 0; j < this->slices; j++) {
            
            // gera pontos
            // vertice A1
            float x1 = this->radius * cos(teta + incrementoTeta) * sin(alpha);
            float y1 = this->radius * sin(teta + incrementoTeta);
            float z1 = this->radius * cos(teta + incrementoTeta) * cos(alpha);
            
            // vertice A2
            float x2 = this->radius * cos(teta) * sin(alpha);
            float y2 = this->radius * sin(teta);
            float z2 = this->radius * cos(teta) * cos(alpha);
            
            // vertice A3
            float x3 = this->radius * cos(teta + incrementoTeta) * sin(alpha + incrementoAlpha);
            float y3 = this->radius * sin(teta + incrementoTeta);
            float z3 = this->radius * cos(teta + incrementoTeta) * cos(alpha + incrementoAlpha);
            
            // vertice A4
            float x4 = this->radius * cos(teta) * sin(alpha + incrementoAlpha);
            float y4 = this->radius * sin(teta);
            float z4 = this->radius * cos(teta) * cos(alpha + incrementoAlpha);
            
            
            
        
            // desenha um quadrado apenas
            // desenho triangulo baixo
            Point *a = new Point(x1,y1,z1);
            this->points.push_back(a);
            
            Point *b = new Point(x2,y2,z2);
            this->points.push_back(b);
            
            Point *c = new Point(x4,y4,z4);
            this->points.push_back(c);
            
            // desenho triangulo cima
            Point *d = new Point(x1,y1,z1);
            this->points.push_back(d);
            
            Point *e = new Point(x4,y4,z4);
            this->points.push_back(e);
            
            Point *f = new Point(x3,y3,z3);
            this->points.push_back(f);
            
            // incremento angulos
            alpha = alpha + incrementoAlpha;
        }
        teta = teta + incrementoTeta;
        
    }
    
}

void sphereToFile(char *filename) {
    
    std::ofstream myfile;
    myfile.open(filename);
    drawSphere();
    
    int vectorLenght = this->points->size();
    
    myfile << vectorLenght << std::endl;
    for (int i=0; i < vectorLenght; i++){
        myfile << *(*points)[i]; // duvida aqui.............. no apontador
    }
    
    myfile.close();
    
}



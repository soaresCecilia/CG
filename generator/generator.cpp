#include <stdlib.h> 
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include "../headers/point.h"
#include "../headers/plane.h"
#include "../headers/box.h"
#include "../headers/cone.h"
#include "../headers/sphere.h"


void executaComandos(int argc, char* argv[]){
  
  
    		if(argc == 4 && !strcmp(argv[1],"plane")){
    			Plane *p = new Plane(atoi(argv[2]));
        		p->planeToFile(argv[3]);
        	}
  
    		if(argc == 7 && !strcmp(argv[1],"box")){
    			Box *b = new Box(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]));
        		b->boxToFile(argv[6]);
        	} 
    		
    
    		if(argc == 6 && !strcmp(argv[1],"sphere")){
    			Sphere *s = new Sphere(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
        		s->sphereToFile(argv[5]);
        	}
    		

    	
    		if(argc == 7 && !strcmp(argv[1],"cone")){
    			Cone *c = new Cone(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
        		c->coneToFile(argv[6]);
        	} 
	}


int main(int argc, char* argv[]) {
    
    executaComandos(argc, argv);

  return 0;
}

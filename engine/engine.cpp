#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif


#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include "../headers/parser.h"
#include "../headers/group.h"


using namespace std;

Group group;

float alfa = 0.0f, beta = 0.5f, radius = 1000.0f;
float camX, camY, camZ;
float x,y,z = 0.0;
float vel = 1.0;

float gt;

void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
}

void changeSize(int w, int h)
{
    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
    h = 1;
    
    // compute window's aspect ratio
    float ratio = w * 1.0 / h;
    
    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();
    
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    
    // Set perspective
    gluPerspective(45.0f, ratio, 1.0f, 2500.0f);
    
    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void axis() {
    // code to draw the x,y,z
    glBegin(GL_LINES);
    
    // X axis in red
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f( 100.0f, 0.0f, 0.0f);
    
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f,  100.0f);
    
    glEnd();
}


void renderScene() {
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // set the camera
    glLoadIdentity();
    gluLookAt(camX,camY,camZ,
              x,y,z,
              0.0f,1.0f,0.0f);
    
    //axis();
    
    
    group.drawSub();

    glutSwapBuffers();
}
void processKeys(unsigned char key, int xx, int yy) {

	switch (key) {
	case 'w':
		z -= vel ;
		break;
	case 'a':
		x -= vel ;
		break;
	case 'd':
		x += vel ;
		break;
	case 's':
		z += vel ;
		break;
	case '-':
		vel -= 1.0f;
		if (vel < 1.0f)
			vel = 1.0f;
		break;

	case '+':
		vel += 1.0f; 
		break;
	case 'q':
		exit(0);
	}

}



void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

	case GLUT_KEY_LEFT:
		alfa += 0.1; break;

	case GLUT_KEY_UP:
		beta += 0.1f;
		if (beta > 1.5f)
			beta = 1.5f;
		break;

	case GLUT_KEY_DOWN:
		beta -= 0.1f;
		if (beta < -1.5f)
			beta = -1.5f;
		break;
	case GLUT_KEY_PAGE_DOWN:
		radius -=vel;
		if (radius < 1.0f)
			radius = 1.0f;
		break;

	case GLUT_KEY_PAGE_UP:
		radius += vel; break;
	
	}
	spherical2Cartesian();
	glutPostRedisplay();

}

void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));

	printf("\nUse Arrows to move the camera up/down and left/right\n");
	printf("Home and End control the distance from the camera to the origin");
}

void initiatingGLUT(int argc, char **argv) {
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Project CG");
    
    // Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    
    // Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);
	spherical2Cartesian();
	printInfo();
    
#ifndef __APPLE__
    glewInit();
#endif

    // OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, GL_LINE);
	
    // Setup Buffers
    glEnableClientState(GL_VERTEX_ARRAY);
}


int main(int argc, char **argv) {
        if (argc == 2) {
                initiatingGLUT(argc, argv);
                Parser().ReadXML(&group, argv[1]);
                // enter GLUT's main cycle
			
                glutMainLoop();
                return 0;
        }

        cerr << "Usage: ./engine <file>.xml" << std::endl;
        return 1;
}

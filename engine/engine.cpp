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
    gluLookAt(5.0,5.0,5.0,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);
    
    axis();
    
    glColor3f(0.1, 1, 1);
    
    
    group.draw();

    glutSwapBuffers();
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
    //glutKeyboardFunc(processKeys);
    //glutSpecialFunc(processSpecialKeys);
    
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

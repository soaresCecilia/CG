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
#include "../headers/nFormasGeo.h"


using namespace std;

nFormasGeo group;

void changeSize(int w, int h) {
        // Prevent a divide by zero, when window is too short
        // (you cant make a window with zero width).
        if (h == 0)
                h = 1;

        // compute window's aspect ratio
        float ratio {w * 1.0f / h};
        // Set the projection matrix as current
        glMatrixMode(GL_PROJECTION);
        // Load Identity Matrix
        glLoadIdentity();
        // Set the viewport to be the entire window
        glViewport(0, 0, w, h);
        // Set perspective
        gluPerspective(45.0f, ratio, 2.5f, 2500.0f);
        // return to the model view matrix mode
        glMatrixMode(GL_MODELVIEW);
}

void renderScene() {
    
        // clear buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        // set the camera
        glLoadIdentity();
        gluLookAt(0.0,0.0,0.0,
                0.0, 0.0, 0.0,
                0.0f, 1.0f, 0.0f);

    
        //axis
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
        glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0f, 0.0f, 0.0f);
        glColor3f(0, 1, 0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 10.0f, 0.0f);
        glColor3f(1, 0, 0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 10.0f);
        glEnd();
    
        group.draw();

        glutSwapBuffers();
}


void initFormaGeo(FormaGeo *f) {
    GLuint buffers[1];
    
    glGenBuffers(1, buffers);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

    int numVertexes = f->getNPoint() * 3;
    size_t vertexesInBytes = sizeof(float) * numVertexes;
    
    int nv = 0;
    float *vertexes = (float *) malloc(sizeof(float) * numVertexes);
    
    for (Point *p : *(f->getVector())) {
        vertexes[nv++] = p->getX();
        vertexes[nv++] = p->getY();
        vertexes[nv++] = p->getZ();
    }
    
    glBufferData(GL_ARRAY_BUFFER, vertexesInBytes, vertexes, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    
    free(vertexes);
}


void initiatingGLUT(int argc, char **argv) {
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Graphical primitives");
    
    //callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    // Callback registration for keyboard processing
    //glutKeyboardFunc(processKeys);
    //glutSpecialFunc(processSpecialKeys);
    
#ifndef __APPLE__
    glewInit();
#endif
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    
    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, GL_LINE);
}

int main(int argc, char **argv) {
        if (argc == 2) {
                Parser().ReadXML(&group, argv[1]);
                initiatingGLUT(argc, argv);
                // enter GLUT's main cycle
                glutMainLoop();
                return 0;
        }

        cerr << "Usage: ./engine <file>.xml" << std::endl;
        return 1;
}

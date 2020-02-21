#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

float CAM_X = sin(0.0) * 5;
float CAM_Y = 5.0;
float CAM_Z = cos(0.0) * 5;
float _X = 0.0;
float _Y = 0.0;
float _Z = 0.0;
float radius = 0.5;
int slices = 10;
int stacks = 10;
double base = 0.5;
double altura = 1.0;
double size = 1.0;

void changeSize(int w, int h) {

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
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

// funçao da esfera
void esfera(double radius, int slices, int stacks) {
	glutWireSphere(radius, slices, stacks);
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(CAM_X, CAM_Y, CAM_Z,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	// put the geometric transformations here
	glTranslatef(_X, _Y, _Z);

	// put drawing instructions here
	
	glBegin(GL_LINES);
		// X axis in red
		glColor3f(1.0f, 0.0f, 0.0f);
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

	// plane 
	glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);

		glVertex3f(-1.0f, 0.0f, 1.0f); //A
		glVertex3f(1.0f, 0.0f, 1.0f); //B
		glVertex3f(1.0f, 0.0f, -1.0f);//C
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
		glVertex3f(1.0f, 0.0f, -1.0f); //C
		glVertex3f(-1.0f, 0.0f, -1.0f); //D
		glVertex3f(-1.0f, 0.0f, 1.0f);//A
	glEnd();


	// esfera
	//glutWireSphere(radius, slices, stacks);

	// box
	//glutWireCube(size);

	// cone
	//glutWireCone(base, altura, slices, stacks);

	// End of frame
	glutSwapBuffers();
}


// write function to process keyboard events

void key_match(unsigned char key, int x, int y) {
	static float px = 0.0;
	static float pz = 0.0;
	switch (key) {
	case 'y':
		CAM_Y -= 0.1;
		break;
	case 't':
		CAM_Y += 0.1;
		break;
	case 'x':
		CAM_X = sin(px) * 5;
		px += 0.1;
		CAM_Z = cos(pz) * 5;
		pz += 0.1;
		break;
	case 'z':
		CAM_X = sin(px) * 5;
		px -= 0.1;
		CAM_Z = cos(pz) * 5;
		pz -= 0.1;
		break;
	
	case 'q':
		exit(0);
	}
	renderScene();
}




int main(int argc, char** argv) {

	// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG@DI-UM");

	// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);


	// put here the registration of the keyboard callbacks
	glutKeyboardFunc(key_match);


	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}

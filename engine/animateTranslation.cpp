#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "../headers/animateTranslation.h"
#include <vector>

animateTranslation::animateTranslation(float a,FormaGeo* p): time(a) {};

animateTranslation::~animateTranslation() {}

void animateTranslation::transform() {
   
}

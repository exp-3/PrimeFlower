#include <iostream>
#include <GL/glut.h>
#include "PrimeFlowerDraw.hpp"

using namespace std;

void idle(void) {
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    PrimeFlowerDraw primeFlowerDraw(1);
    primeFlowerDraw.init(argc, argv);
    glutDisplayFunc(primeFlowerDraw.sDisplay);
    glutReshapeFunc(primeFlowerDraw.sReshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

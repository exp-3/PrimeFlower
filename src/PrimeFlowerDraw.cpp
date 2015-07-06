#include "PrimeFlowerDraw.hpp"
#include <iostream>

PrimeFlowerDraw *PrimeFlowerDraw::self = NULL;

PrimeFlowerDraw::PrimeFlowerDraw(int num) : primeFlower(PrimeFlower(num)) {
    self = this;
}

void PrimeFlowerDraw::baseInit(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("PrimeFlower");
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void PrimeFlowerDraw::objectInit() {
    //objectID = glGenLists(1);
    //glNewList(objectID, GL_COMPILE);
    //primeFlower.display();
    //glEndList();
}

void PrimeFlowerDraw::init(int argc, char *argv[]) {
    baseInit(argc, argv);
    objectInit();
}

void PrimeFlowerDraw::reshape(int w, int h) {
    glViewport(0, 0, w, h);

    glLoadIdentity();

    glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void PrimeFlowerDraw::setMatrix() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
}

void PrimeFlowerDraw::resetMatrix() {
    glPopMatrix();
}

void PrimeFlowerDraw::display() {
    static int count = 0;
    if(count % 60 == 0) {
        primeFlower.setNumber(count / 60);
    }
    setMatrix();
    //glCallList(objectID);
    primeFlower.display();
    resetMatrix();
    glutSwapBuffers();
    count++;
}

void PrimeFlowerDraw::sReshape(int w, int h) {
    self->reshape(w, h);
}

void PrimeFlowerDraw::sDisplay() {
    self->display();
}

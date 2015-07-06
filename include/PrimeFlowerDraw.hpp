#pragma once

#include <GL/glut.h>

#include "PrimeFlower.hpp"

class PrimeFlowerDraw {
public:
    PrimeFlowerDraw(int num);
    void init(int argc, char *argv[]);
    void reshape(int w, int h);
    void display();

    static void sReshape(int w, int h);
    static void sDisplay();

protected:
    void baseInit(int argc, char *argv[]);
    void objectInit();
    void setMatrix();
    void resetMatrix();
    static PrimeFlowerDraw *self;
    GLuint objectID;
    PrimeFlower primeFlower;
};

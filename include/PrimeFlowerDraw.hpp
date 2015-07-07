#pragma once

#include <GL/glut.h>

#include "PrimeFlower.hpp"

class PrimeFlowerDraw {
public:
    /** コンストラクタ*/
    PrimeFlowerDraw(int num);

    /** OpenGLの初期化*/
    void init(int argc, char *argv[]);

    /** reshape要求時の関数*/
    void reshape(int w, int h);

    /** display要求時の関数*/
    void display();

    /** reshapeイベントハンドラのための形式的な関数*/
    static void sReshape(int w, int h);

    /** displayイベントハンドラのための形式的な関数*/
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

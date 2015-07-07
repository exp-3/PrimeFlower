#pragma once

#include <vector>
#include <GL/glut.h>

#include "Circle.hpp"
#include "Factrize.hpp"

class PrimeFlower {
public:
    /** コンストラクタ*/
    PrimeFlower(int num);

    /** メンバ変数に設定されている数だけの点を素因数分解して花のように表示する*/
    void display();

    /** 点の数を設定する*/
    void setNumber(int num);

protected:
    void fractal(std::vector<int>& factors, double x, double y, double radius, double angle);

    double scale;
    std::vector<Circle> circles;
    std::vector<Circle>::iterator counter;
};

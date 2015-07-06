#pragma once

#include <vector>
#include <GL/glut.h>

#include "Circle.hpp"
#include "factrize.hpp"

class PrimeFlower {
public:
    PrimeFlower(int num);
    void display();
    void setNumber(int num);

protected:
    void fractal(std::vector<int> factors, double x, double y, double radius, double angle);

    double scale;
    std::vector<int> factors;
    std::vector<Circle> circles;
    std::vector<Circle>::iterator counter;
};

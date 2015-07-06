#pragma once

#include <cmath>
#include <map>

class Circle {
public:
    Circle();
    void setScale(double tScale);
    void setPosition(double tX, double tY, double tZ);
    void display();

protected:
    class Vertices : public std::multimap<double, double> {
    public:
        Vertices(int num);
    };

    int count;
    double srcX, srcY, srcZ, dstX, dstY, dstZ, scale;
    static int num;
    static Vertices vertices;
};

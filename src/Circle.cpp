#include "Circle.hpp"
#include <GL/glut.h>
#include <iostream>

int Circle::num = 1000;
Circle::Vertices Circle::vertices = Circle::Vertices(num);

Circle::Circle() {
}

Circle::Vertices::Vertices(int num) {
    for(int i = 0; i < num; i++) {
        double theta = 2 * i * M_PI / num;
        insert(std::make_pair(cos(theta), sin(theta)));
    }
}

void Circle::setScale(double tScale) {
    scale = tScale;
}

void Circle::setPosition(double tX, double tY, double tZ) {
    srcX = dstX;
    srcY = dstY;
    srcZ = dstZ;
    dstX = tX;
    dstY = tY;
    dstZ = tZ;
    count = 0;
}

void Circle::display() {
    double x, y, z;
    if(count < 10) {
        x = (srcX * (10 - count) + dstX * count) / 10;
        y = (srcY * (10 - count) + dstY * count) / 10;
        z = (srcZ * (10 - count) + dstZ * count) / 10;
        count++;
    } else {
        x = dstX;
        y = dstY;
        z = dstZ;
    }
    glColor3d(1.0, 0.8, 0.0);
    glPushMatrix();
    glTranslated(x, y, z);
    glScaled(scale, scale, scale);
    glBegin(GL_POLYGON);
    for(auto itr = vertices.begin(); itr != vertices.end(); itr++) {
        glVertex2d(itr->first, itr->second);
    }
    glEnd();
    glPopMatrix();
}

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
    srcScale = dstScale;
    dstScale = tScale;
    countFromScaleSetting = 0;
}

void Circle::setPosition(double tX, double tY, double tZ) {
    srcX = dstX;
    srcY = dstY;
    srcZ = dstZ;
    dstX = tX;
    dstY = tY;
    dstZ = tZ;
    countFromPositionSetting = 0;
}

void Circle::display() {
    double x, y, z, scale;
    if(countFromPositionSetting < 10) {
        x = (srcX * (10 - countFromPositionSetting) + dstX * countFromPositionSetting) / 10;
        y = (srcY * (10 - countFromPositionSetting) + dstY * countFromPositionSetting) / 10;
        z = (srcZ * (10 - countFromPositionSetting) + dstZ * countFromPositionSetting) / 10;
        countFromPositionSetting++;
    } else {
        x = dstX;
        y = dstY;
        z = dstZ;
    }

    if(countFromScaleSetting < 10) {
        scale = (srcScale * (10 - countFromScaleSetting) + dstScale * countFromScaleSetting) / 10;
        countFromScaleSetting++;
    } else {
        scale = dstScale;
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

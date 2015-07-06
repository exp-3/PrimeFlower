#include "PrimeFlower.hpp"

PrimeFlower::PrimeFlower(int num) {
    scale = 0.95;
    circles.reserve(10000);
    setNumber(num);
}

void PrimeFlower::display() {
    for(auto itr = circles.begin(); itr != circles.end(); itr++) {
        itr->display();
    }
}

void PrimeFlower::setNumber(int num) {
    std::vector<int> factors = factrize(num);
    if(num > (int) circles.size()) {
        if(circles.empty()) {
            circles.push_back(Circle());
        }
        int gap = num - (int) circles.size();
        for(int i = 0; i < gap; i++) {
            circles.push_back(circles.back());
        }
    } else if(num < (int) circles.size()) {
        circles.erase(circles.begin() + num, circles.end());
    }
    counter = circles.begin();
    fractal(factors, 0.0, 0.0, 1.0, 0.0);
}

void PrimeFlower::fractal(std::vector<int>& factors, double x, double y, double radius, double angle) {
    if(factors.empty()) {
        return;
    }

    int vertices = factors.back();

    if(vertices == 1) {
        counter->setPosition(x, y, 0.0);
        counter->setScale(radius);
        counter++;
    } else if(vertices > 1) {
        double childRadius = scale * radius * (1 - 1 / (1 + sin(M_PI / vertices)));
        radius -= childRadius;

        factors.pop_back();
        for(int i = 0; i < vertices; i++) {
            double theta = 2 * i * M_PI / vertices + angle;
            fractal(factors, x - radius * sin(theta), y + radius * cos(theta), childRadius, theta);
        }
        factors.push_back(vertices);
    }
}

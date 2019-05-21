#pragma once
#include "Point.h"

class Square {
private:
    Point point1;
    Point point2;
    Point point3;
    Point point4;

    bool isSquare();

public:
    Square();
    Square(Point, Point, Point, Point);
    ~Square();

    double Circumference();
    double Area();
};
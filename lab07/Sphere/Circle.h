#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
protected:
    double x, y, r;
public:
    Circle(double, double, double);
    double area();
};

#endif
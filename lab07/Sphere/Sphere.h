#ifndef SPHERE_H
#define SPHERE_H

#include "Circle.h"

class Sphere final : public Circle{
private:
    double z;
public:
    Sphere(double, double, double, double);
    double area();
};

#endif
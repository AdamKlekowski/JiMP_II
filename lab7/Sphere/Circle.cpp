#include "Circle.h"

#define PI 3.14

Circle::Circle(double r, double x, double y) 
{
    this->r=r;
    this->x=x;
    this->y=y;
}

double Circle::area() 
{
    return PI*r*r;
}
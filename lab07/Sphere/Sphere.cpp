#include "Sphere.h"
    
Sphere::Sphere(double r, double x, double y, double z) : Circle(r,x,y)
{
    this->z=z;
}

double Sphere::area() 
{
    return 4*Circle::area();
}
#include <iostream>
using ::std::cout;
using ::std::endl;

#include "Circle.h"
#include "Sphere.h"

int main()
{
    Circle *myCircle = new Circle(2, 0, 0);
    Sphere *mySphere = new Sphere(4, 1, 1, 1);

    cout << "Area of Circle: " << myCircle->area() << endl;
    cout << "Area of Sphere: " << mySphere->area() << endl;
}
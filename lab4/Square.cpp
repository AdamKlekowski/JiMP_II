#include<cmath>
using ::std::pow;

#include "Square.h"

bool Square::isSquare()
{
    if (point1.Distance(point2)==point2.Distance(point3) &&
        point2.Distance(point3)==point3.Distance(point4) &&
        point3.Distance(point4)==point4.Distance(point1))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

Square::Square() : point1(0,0), point2(0,0), point3(0,0), point4(0,0) {}

Square::Square(Point p1, Point p2, Point p3, Point p4) : point1(p1), point2(p2), point3(p3), point4(p4) {}

Square::~Square() {}

double Square::Circumference() 
{
    if(isSquare())
    {
        return 4*(point1.Distance(point2));
    }
    else
    {
        return -1;
    }
}

double Square::Area()
{
    if(isSquare())
    {
        return pow(point1.Distance(point2),2);
    }
    else
    {
        return -1;
    }
}
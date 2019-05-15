#include <cmath>
using ::std::pow;
using ::std::sqrt;

#include <ostream>
using ::std::ostream;
using ::std::endl;

#include "Point.h"


Point::Point():x(0),y(0) {}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
     
Point::~Point(){}

void Point::ToString(ostream *out) const
{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}
     
double Point::Distance(const Point &other) const
{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

double Point::GetX() const 
{
    return x;
}

double Point::GetY() const 
{
    return y;
}

void Point::SetX(double x) 
{
    this->x=x;
}

void Point::SetY(double y) 
{
    this->y=y;
}


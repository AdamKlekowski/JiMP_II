#include "Square.h"
#include "Point.h"

#include <iostream>
using ::std::cout;

#include <memory>
using ::std::unique_ptr;
using ::std::make_unique;

int main()
{
    Point p1(0,0);
    Point p2(2,0);
    Point p3(2,2);
    Point p4(0,2);

    auto mySquare = make_unique <Square>(p1,p2,p3,p4);
    cout<< "Pole: " << mySquare->Area() << std::endl;
    cout<< "Obwód: " << mySquare->Circumference() << std::endl;

    Point p5(10,10);
    auto notSquare=make_unique <Square>(p1,p2,p3,p5);
    cout<< "Pole: " << notSquare->Area() << std::endl;
    cout<< "Obwód: " << notSquare->Circumference() << std::endl;

}
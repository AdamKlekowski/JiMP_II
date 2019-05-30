#include <iostream>

#include "Matrix.h"
#include "Osoba.h"
#include "Insurance.h"
#include "Car.h"
#include "House.h"
#include "InvalidElementPositionException.h"

int main()
{
    //Matrix
    Matrix<int> myMatrix(5,5);
    try{
        myMatrix.setAt(6, 2, 0);
    }
    catch (const InvalidElementPositionException &error){
        std::cerr << error.what() << ": " << error.GetDetails() << std::endl;
    }

    //Osoba
    Osoba student("Adam", "Klekowski", 19);
    ++student;
    std::cout << student;
    Osoba unkownPerson;
    std::cin >> unkownPerson;
    if (student==unkownPerson) std::cout << "People are the same" << std::endl;

    //Insurance
    Insurance *unkownInsurance=new Car();
    unkownInsurance->Calculate();

    unkownInsurance=new House();
    unkownInsurance->Calculate();
}
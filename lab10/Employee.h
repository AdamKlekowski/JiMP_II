#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

class Employee : public Person{
private:
    double salary;

public:
    Employee(const std::string id, const std::string name, 
            const std::string surname, const double salary);
    friend std::ostream& operator<< (std::ostream &output, const Employee &student);
};

#endif
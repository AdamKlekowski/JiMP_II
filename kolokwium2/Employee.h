#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee{
private:
    std::string name;
    std::string surname;
    double salary;

public:
    Employee();
    Employee(std::string, std::string, double);

    friend std::istream& operator>> (std::istream &input, Employee &employee);
    friend std::ostream& operator<< (std::ostream &output, const Employee &employee);
    bool operator== (const Employee &employee) const;

    std::string GetName() const;
    std::string GetSurname() const;
    double GetSalary() const;
};

#endif
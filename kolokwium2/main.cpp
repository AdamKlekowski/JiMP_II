#include <iostream>

#include "Employee.h"
#include "EmployeeComparator.h"
#include "ByFirstNameAscending.h"
#include "ByLastNameAscending.h"
#include "BySalaryDescending.h"

int main()
{
    Employee IBMemployee("Adam", "Klekowski", 4500);
    Employee ABBemployee("Elon", "Jobs", 12500);
    Employee unknownEmployee;

    std::cin >> unknownEmployee;
    std::cout << "Unknown employee: " << std::endl << unknownEmployee << std::endl;

    std::cout << "IBM employee: " << std::endl << IBMemployee << std::endl;

    EmployeeComparator *comparator = new ByFirstNameAscending();
    if (comparator->IsLess(IBMemployee, ABBemployee)) {
        std::cout << "First name is not less" << std::endl;
    }
    else {
        std::cout << "First name is less" << std::endl; 
    }


    comparator = new ByLastNameAscending();
    if (comparator->IsLess(IBMemployee, ABBemployee)) {
        std::cout << "Last name is not less" << std::endl;
    }
    else {
        std::cout << "Last name is less" << std::endl; 
    }


    comparator = new BySalaryDescending();
    if (comparator->IsLess(IBMemployee, ABBemployee)) {
        std::cout << "Salary is less" << std::endl;
    }
    else {
        std::cout << "Salary is not less" << std::endl; 
    }


    if (IBMemployee == ABBemployee) {
        std::cout << "Salaries are same" << std::endl;
    }
    else {
        std::cout << "Salaries are not same" << std::endl; 
    }
}
#ifndef EMPLOYEE_COMPARATOR_H
#define EMPLOYEE_COMPARATOR_H

#include "Employee.h"

class EmployeeComparator{
public:
    virtual ~EmployeeComparator() {}
    virtual bool IsLess(const Employee &left, const Employee &right) = 0;
};

#endif
#ifndef BY_SALARY_DESCENDING_H
#define BY_SALARY_DESCENDING_H

#include "EmployeeComparator.h"

class BySalaryDescending : public EmployeeComparator{
public:
    virtual bool IsLess(const Employee &left, const Employee &right) override;
};

#endif
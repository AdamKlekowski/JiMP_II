#ifndef BY_FIRST_NAME_ASCENDING_H
#define BY_FIRST_NAME_ASCENDING_H

#include "EmployeeComparator.h"

class ByFirstNameAscending : public EmployeeComparator{
public:
    virtual bool IsLess(const Employee &left, const Employee &right) override;
};

#endif
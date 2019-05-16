#ifndef BY_LAST_NAME_ASCENDING_H
#define BY_LAST_NAME_ASCENDING_H

#include "EmployeeComparator.h"

class ByLastNameAscending : public EmployeeComparator{
public:
    virtual bool IsLess(const Employee &left, const Employee &right) override;
};

#endif
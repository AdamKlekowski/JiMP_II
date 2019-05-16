#include "BySalaryDescending.h"

bool BySalaryDescending::IsLess(const Employee &left, const Employee &right)
{
    return left.GetSalary() < right.GetSalary();
}


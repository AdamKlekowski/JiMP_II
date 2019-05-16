#include "ByFirstNameAscending.h"

bool ByFirstNameAscending::IsLess(const Employee &left, const Employee &right) 
{
    return ( left.GetName() > right.GetName() );
}


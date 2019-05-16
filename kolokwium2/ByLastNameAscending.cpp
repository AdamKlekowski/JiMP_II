#include "ByLastNameAscending.h"

bool ByLastNameAscending::IsLess(const Employee &left, const Employee &right) 
{
    return ( left.GetSurname() > right.GetSurname() );
}


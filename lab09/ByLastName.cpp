#include "ByLastName.h"

ByLastName::ByLastName(string pattern) 
{
    this->pattern=pattern;
}

bool ByLastName::Accept(const Student &student) 
{
    return student.GetLastName()==pattern;
}
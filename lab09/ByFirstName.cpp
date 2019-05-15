#include "ByFirstName.h"

ByFirstName::ByFirstName(string pattern) 
{
    this->pattern=pattern;
}

bool ByFirstName::Accept(const Student &student) 
{
    return student.GetFirstName()==pattern;
}
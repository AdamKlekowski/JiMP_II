#include "ByYearLowerOrEqualTo.h"

ByYearLowerOrEqualTo::ByYearLowerOrEqualTo(int year) 
{
    this->year=year;
}

bool ByYearLowerOrEqualTo::Accept(const Student &student) 
{
    return student.GetStudyYear()<=year;
}
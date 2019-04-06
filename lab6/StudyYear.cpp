#include "StudyYear.h"

StudyYear::StudyYear() {}

StudyYear::StudyYear(int newValue) : value(newValue) {}

StudyYear& StudyYear::operator++ () 
{
    ++value;
    return *this;
}

StudyYear StudyYear::operator++ (int) 
{
    StudyYear copy = (*this);
    ++value;
    return copy;
}

StudyYear& StudyYear::operator-- () 
{
    --value;
    return *this;
}

StudyYear StudyYear::operator-- (int) 
{
    StudyYear copy = (*this);
    --value;
    return copy;
}

bool StudyYear::operator== (const StudyYear& objectToCompare)
{
    if (value==objectToCompare.value) { return true; }
    else { return false; }
}

bool StudyYear::operator< (const StudyYear& objectToCompare)
{
    if (value<objectToCompare.value) { return true; }
    else { return false; }
}

StudyYear::operator int() 
{
    return value;
}

istream& operator>> (istream &input, StudyYear& studyYear)
{
    input >> studyYear.value;
    return input;
}

ostream& operator<< (ostream &output, const StudyYear& studyYear)
{
    return output<< "year " << studyYear.value;
}
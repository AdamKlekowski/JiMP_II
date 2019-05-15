#include "ByOneOfPrograms.h"

ByOneOfPrograms::ByOneOfPrograms(std::vector<string> const &searchingFields) 
{
    patterns=searchingFields;
}

bool ByOneOfPrograms::Accept(const Student &student) 
{
    for(string pattern : patterns)
    {
        if(student.GetField()==pattern) return true;
    }
    return false;
}
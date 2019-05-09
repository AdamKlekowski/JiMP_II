#include "OrQuery.h"

OrQuery::OrQuery(std::vector<std::unique_ptr<Query>> &queries) : patterns(queries) {}

bool OrQuery::Accept(const Student &student) 
{
    for (int i=0; i<patterns.size(); i++)
    {
        if(patterns.at(i)->Accept(student)) return true;
    }
    return false;
}
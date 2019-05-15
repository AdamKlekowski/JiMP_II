#include "AndQuery.h"

AndQuery::AndQuery(std::vector<std::unique_ptr<Query>> &queries) : patterns(queries) {}

bool AndQuery::Accept(const Student &student) 
{
    for (int i=0; i<patterns.size(); i++)
    {
        if(! patterns.at(i)->Accept(student)) return false;
    }
    return true;
}
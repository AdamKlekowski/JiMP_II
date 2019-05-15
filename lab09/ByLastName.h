#ifndef BYLASTNAME_H
#define BYLASTNAME_H

#include "Student.h"
#include "Query.h"

class ByLastName : public Query{
private:
    string pattern;
public:
    ByLastName(string);
    virtual bool Accept(const Student &student) override;
};

#endif
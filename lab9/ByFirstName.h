#ifndef BYFIRSTNAME_H
#define BYFIRSTNAME_H

#include "Student.h"
#include "Query.h"

class ByFirstName : public Query{
private:
    string pattern;
public:
    ByFirstName(string);
    virtual bool Accept(const Student &student) override;
};

#endif
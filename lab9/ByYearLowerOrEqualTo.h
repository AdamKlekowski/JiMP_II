#ifndef BYYEAR_H
#define BYYEAR_H

#include "Student.h"
#include "Query.h"

class ByYearLowerOrEqualTo : public Query{
private:
    int year;
public:
    ByYearLowerOrEqualTo(int);
    virtual bool Accept(const Student &student) override;
};

#endif
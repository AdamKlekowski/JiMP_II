#ifndef QUERY_H
#define QUERY_H

#include "Student.h"

class Query{
public:
    virtual ~Query() {}
    virtual bool Accept(const Student &student) = 0;
};

#endif
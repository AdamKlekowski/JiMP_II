#ifndef BYONEOFPROGRAMS_H
#define BYONEOFPROGRAMS_H

#include <vector>
#include "Student.h"
#include "Query.h"

class ByOneOfPrograms : public Query{
private:
    std::vector<string> patterns;
public:
    ByOneOfPrograms(std::vector<string> const &searchingFields);
    virtual bool Accept(const Student &student) override;
};

#endif
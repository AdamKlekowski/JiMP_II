#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <memory>
#include <vector>
#include "Student.h"
#include "Query.h"

class AndQuery : public Query{
private:
    std::vector<std::unique_ptr<Query>> &patterns;
public:
    AndQuery(std::vector<std::unique_ptr<Query>> &queries);
    virtual bool Accept(const Student &student) override;
};

#endif
#ifndef ORQUERY_H
#define ORQUERY_H

#include <memory>
#include <vector>
#include "Student.h"
#include "Query.h"

class OrQuery : public Query{
private:
    std::vector<std::unique_ptr<Query>> &patterns;
public:
    OrQuery(std::vector<std::unique_ptr<Query>> &queries);
    virtual bool Accept(const Student &student) override;
};

#endif
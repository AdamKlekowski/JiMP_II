#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <vector>

#include <iostream>
#include "ByNameQuery.h"
#include "IndexInUseException.h"
#include "NotFoundException.h"
using namespace std;

template <typename T>
class Repository{
private:
    std::vector<T> content;

public:
    T operator[] (const std::string index) const;

    void Append(const T &newElement);
    void Print() const;
    size_t Size() const;
    std::vector<T> FindBy(const ByNameQuery &query) const;
};

#endif
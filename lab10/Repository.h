#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <vector>

template <typename T>
class Repository{
private:
    std::vector<T> content;

public:
    T operator[] (const std::string index) const;
    void Append(const T& newElement);
    void Print() const;
    size_t Size() const;
    //FindBy(Query) const;
};

#endif
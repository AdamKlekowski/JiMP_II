#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <iostream>
#include <vector>
#include "ByNameQuery.h"
#include "IndexInUseException.h"
#include "NotFoundException.h"

template <typename T>
class Repository{
private:
    std::vector<T> content;

public:
    T operator[] (const std::string index) const
    {
        for(auto element :  content)
        {
            if(index == element.GetID()) return element;
        }
        throw NotFoundException(index);
    }

    void Append(const T &newElement) 
    {
        for(auto element : content)
        {
            if(newElement.GetID() == element.GetID()) throw IndexInUseException(newElement.GetID());
        }
        content.push_back(newElement);
    }

    void Print() const
    {
        std::cout << std::endl << "----- content of repository ----- ";
        for(auto element : content)
        {
            std::cout << std::endl << element;
        }
        std::cout << "----- end of content ----- " << std::endl << std::endl;
    }

    size_t Size() const { return content.size(); }

    std::vector<T> FindBy(const ByNameQuery &query) const
    {
        std::vector<T> queryResult;
        for(auto element : content)
        {
            if(query.Accept(element)) queryResult.push_back(element);
        }
        return queryResult;
    }
};

#endif
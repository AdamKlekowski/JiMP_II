#include <iostream>
#include "Repository.h"
#include "NotFoundException.h"

template <typename T>
T Repository<T>::operator[](const std::string index) const 
{
    for(auto element :  content)
    {
        if(index == content.id) return element;
    }
    throw NotFoundException(index);
}

template <typename T>
void Repository<T>::Append(const T& newElement) 
{
    content.push_back(newElement);
}

template <typename T>
void Repository<T>::Repository::Print() const 
{
    for(auto element : content)
    {
        std::cout << element << std::endl;
    }
}

template <typename T>
size_t Repository<T>::Repository::Size() const 
{
    return content.size();
}
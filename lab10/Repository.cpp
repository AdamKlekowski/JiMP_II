#include "Repository.h"

#include <iostream>
#include "ByNameQuery.h"
#include "IndexInUseException.h"
#include "NotFoundException.h"

template <class T>
T Repository<T>::operator[] (const std::string index) const
{
    for(auto element :  content)
    {
        if(index == element.GetID()) return element;
    }
    throw NotFoundException(index);
}

template <typename T>
void Repository<T>::Append(const T &newElement) 
{
    for(auto element : content)
    {
        if(newElement.GetID() == element.GetID()) throw IndexInUseException(newElement.GetID());
    }
    content.push_back(newElement);
}

template <typename T>
void Repository<T>::Print() const
{
    std::cout << std::endl << "----- content of repository ----- ";
    for(auto element : content)
    {
        std::cout << std::endl << element;
    }
    std::cout << "----- end of content ----- " << std::endl << std::endl;
}

template <typename T>
size_t Repository<T>::Size() const { return content.size(); }

template <typename T>
std::vector<T> Repository<T>::FindBy(const ByNameQuery &query) const
{
    std::vector<T> queryResult;
    for(auto element : content)
    {
        if(query.Accept(element)) queryResult.push_back(element);
    }
    return queryResult;
}

#include "Student.h"
#include "Employee.h"
template class Repository <Employee>;
template class Repository <Student>;
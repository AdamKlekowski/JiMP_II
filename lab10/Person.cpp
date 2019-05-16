#include "Person.h"

Person::Person (const std::string id, const std::string name, const std::string surname) 
{
    this->id=id;
    this->name=name;
    this->surname=surname;
}

std::string Person::GetID() const { return id; }
std::string Person::GetName() const { return name; }
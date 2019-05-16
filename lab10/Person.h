#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
protected:
    std::string id;
    std::string name;
    std::string surname;

public:
    Person(const std::string id, const std::string name, const std::string surname);
    std::string GetID() const;
    std::string GetName() const;
};

#endif
#include "Osoba.h"

Osoba::Osoba() {}

Osoba::Osoba(std::string name, std::string surname, int age)
{
    this->name=name;
    this->surname=surname;
    this->age=age;    
}

Osoba& Osoba::operator++ () 
{
    ++age;
    return *this;
}

bool Osoba::operator== (const Osoba& objectToCompare)
{
    return  name==objectToCompare.name &&
            surname==objectToCompare.surname &&
            age==objectToCompare.age;
}

std::istream& operator>> (std::istream &input, Osoba& person)
{
    input >> person.name >> person.surname >> person.age;
    return input;
}

std::ostream& operator<< (std::ostream &output, const Osoba& person)
{
    return output   << "name: " << person.name << std::endl
                    << "surname: " << person.surname << std::endl
                    << "age: " << person.age << std::endl;
}
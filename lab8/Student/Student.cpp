#include <iostream>
using ::std::ostream;
using ::std::istream;

#include <set>
using ::std::set;

#include <string>
using ::std::string;

#include <regex>
using ::std::regex;
using ::std::regex_match;

#include "Student.h"
#include "InvalidNameSurnameException.h"
#include "InvalidNameCharactersException.h"
#include "InvalidAgeException.h"
#include "InvalidProgramException.h"

void Student::validate() 
{
    if(!isNameSurnameValid()) throw InvalidNameSurnameException(firstName, lastName);
    if(!isNameCharactersValid()) throw InvalidNameCharactersException(firstName, lastName);
    if(!isAgeValid()) throw InvalidAgeException(age);
    if(!isProgramValid()) throw InvalidProgramException(field);
}

bool Student::isNameSurnameValid() 
{
    if (!regex_match (firstName, regex("^[A-Z][a-z]*$") )) { return false; }
    else if (!regex_match (lastName, regex("^[A-Z][a-z]*$") )) { return false; }
    return true;
}

bool Student::isNameCharactersValid() 
{
    if (!regex_match (firstName, regex("^[A-Za-z]*$") )) { return false; }
    else if (!regex_match (lastName, regex("^[A-Za-z]*$") )) { return false; }
    return true;
}

bool Student::isAgeValid() 
{
    if (age<10 || age>100) return false;
    return true;
}

bool Student::isProgramValid() 
{
    string fields[]={"IT", "Economy", "Law", "Medicine", "Construction"};
    set<string> availableFields(fields, fields+5);
    if(availableFields.find(field) == availableFields.end()) return false;
    return true;
}

Student::Student() {}

Student::Student(string firstName, string lastName, string field, int age)
{
    this->firstName=firstName;
    this->lastName=lastName;
    this->field=field;
    this->age=age;
    validate();
}

istream& operator>> (istream &input, Student& student)
{
    input >> student.firstName >> student.lastName >> student.field >> student.age;
    return input;
}

ostream& operator<< (ostream &output, const Student& student)
{
    return output   << "{firstName: \"" << student.firstName << "\", "
                    << "lastName: \"" << student.lastName << "\", "
                    << "field: \"" << student.field << "\", "
                    << "age: \"" << student.age << "\"}";
}
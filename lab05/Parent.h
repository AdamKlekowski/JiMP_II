#pragma once
#include <string>
using ::std::string;

#include "Child.h"

class Parent
{
private:
    string firstName;
    string lastName;
    int age;
    Child *child;

public:
    Parent(string, string, int, Child*);
    ~Parent();

    string getChildSchool();
    string getChildFirstName();

    void assignToOtherSchool(string);
    void changeChildFirstName (string);
};
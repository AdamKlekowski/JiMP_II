#include "Child.h"

Child::Child(string fName, string lName, int age, string school)
{
    firstName=fName;
    lastName=lName;
    this->age=age;
    this->school=school;
}

Child::~Child() {}
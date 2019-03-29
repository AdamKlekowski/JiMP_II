#include "Parent.h"

Parent::Parent(string fName, string lName, int age, Child *child)
{
    firstName=fName;
    lastName=lName;
    this->age=age;
    this->child=child;
}

Parent::~Parent() 
{
    delete child;
}

string Parent::getChildSchool()
{
    return child->school;
}

string Parent::getChildFirstName()
{
    return child->firstName;
}

void Parent::assignToOtherSchool(string name)
{
    child->school=name;
}

void Parent::changeChildFirstName (string newName)
{
    child->firstName=newName;
}
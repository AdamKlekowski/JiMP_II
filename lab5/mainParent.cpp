#include<iostream>
using ::std::cout;
using ::std::endl;

#include<memory>
using ::std::make_unique;

#include "Parent.h"
#include "Child.h"


int main()
{
    auto child=make_unique<Child>("Adam", "Klekowski", 20, "AGH");
    auto parent=make_unique<Parent>("Krzysztof", "Klekowski", 40, child.release());

    cout << parent->getChildSchool() << endl;
    parent->assignToOtherSchool("UJ");
    cout << parent->getChildSchool() << endl;

    cout << parent->getChildFirstName() << endl;
    parent->changeChildFirstName("Lukasz");
    cout << parent->getChildFirstName() << endl;
}
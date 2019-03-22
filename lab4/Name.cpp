#include "Name.h"
#include <string>
using ::std::to_string;

#include <vector>
using ::std::vector;


auto Name::splitNames(const string &namesAndSurname)
{
    vector<string> names;
    string tmp="";
    for (char letter : namesAndSurname)
    {
        if (letter==' ')
        {
            tmp+=letter;
            names.push_back(tmp);
            tmp="";
        }
        else
        {
            tmp+=letter;
        }
    }
    tmp+=' ';
    names.push_back(tmp);
    return names;
}

Name::Name(const string &namesAndSurname)
{
    auto names=splitNames(namesAndSurname);
    if (names.size()==2)
    {
        firstName=names.at(0);
        secondName="";
        thirdName="";
        lastName=names.at(1);
    } 
    else if (names.size()==3)
    {
        firstName=names[0];
        secondName=names[1];
        thirdName="";
        lastName=names[2];
    }
    else if (names.size()==4)
    {
        firstName=names[0];
        secondName=names[1];
        thirdName=names[2];
        lastName=names[3];
    }  
}

string Name::FirstName() const
{
    return firstName;
}

string Name::SecondName() const
{
    return secondName;
}

string Name::ThirdName() const
{
    return thirdName;
}

string Name::Surname() const
{
    return lastName;
}

string Name::ToFullInitials() const 
{
    string fullInitials="";
    fullInitials+=firstName.at(0);
    fullInitials+=". ";
    if (secondName!="") 
    {
        fullInitials+=secondName.at(0);
        fullInitials+=". ";
    }
    if (thirdName!="") 
    {
        fullInitials+=thirdName.at(0);
        fullInitials+=". ";
    }
    fullInitials+=lastName.at(0);
    fullInitials+=".";
    return fullInitials;
}

string Name::ToFirstNamesInitials() const 
{
    string fullInitials="";
    fullInitials+=firstName.at(0);
    fullInitials+=". ";
    if (secondName!="") 
    {
        fullInitials+=secondName.at(0);
        fullInitials+=". ";
    }
    if (thirdName!="") 
    {
        fullInitials+=thirdName.at(0);
        fullInitials+=". ";
    }
    fullInitials+=lastName;
    return fullInitials;
}

string Name::ToSurnameNames() const 
{
    return lastName+firstName+secondName+thirdName;
}

string Name::ToNamesSurname() const 
{
    return firstName+secondName+thirdName+lastName;
}

bool Name::IsBeforeBySurname(const Name &other) const 
{
    for (int i=0; i<other.lastName.size() && i<lastName.size(); i++)
    {
        if (other.lastName.at(i)==lastName.at(i)) {}
        else
        {
            if (other.lastName.at(i)>lastName.at(i)) { return false; }
            else { return true; }
        }
    }
}

bool Name::IsBeforeByFirstName(const Name &other) const 
{
    for (int i=0; i<other.firstName.size() && i<firstName.size(); i++)
    {
        if (other.firstName.at(i)==firstName.at(i)) {}
        else
        {
            if (other.firstName.at(i)>firstName.at(i)) { return false; }
            else { return true; }
        }
    }
}
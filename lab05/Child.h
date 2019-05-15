#pragma once
#include<string>
using ::std::string;

class Child
{
private:
    string firstName;
    string lastName;
    int age;
    string school;
    
public:
    Child(string, string, int, string);
    ~Child();

    friend class Parent;
};
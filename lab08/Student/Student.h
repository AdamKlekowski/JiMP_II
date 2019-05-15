#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using ::std::string;

#include <iostream>
using ::std::ostream;
using ::std::istream;

class Student{
private:
    string firstName;
    string lastName;
    string field;
    int age;

    bool isNameSurnameValid();
    bool isNameCharactersValid();
    bool isAgeValid();
    bool isProgramValid();

public:
    Student();
    Student(string, string, string, int);

    void validate();

    friend istream& operator>> (istream&, Student&);
    friend ostream& operator<< (ostream &, const Student&);
};

#endif
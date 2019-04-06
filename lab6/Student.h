#pragma once
#include<string>
using ::std::string;

#include "StudyYear.h"

class Student{
private:
    string id;
    string firstName;
    string lastName;
    string field;
    StudyYear year;

public:
    Student();
    Student(string, string, string, string, int);

    friend istream& operator>> (istream&, Student&);
    friend ostream& operator<< (ostream &output, const Student& student);

    friend class StudentRepository;
};

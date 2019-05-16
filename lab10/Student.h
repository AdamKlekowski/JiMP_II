#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"

class Student : public Person{
private:
    std::string faculty;

public:
    Student(const std::string id, const std::string name, 
            const std::string surname, const std::string faculty);
    friend std::ostream& operator<< (std::ostream &output, const Student  &student);
};

#endif
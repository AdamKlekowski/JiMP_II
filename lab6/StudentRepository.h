#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include<vector>
using ::std::vector;

#include "Student.h"

class StudentRepository{
private:
    vector<Student> students;

public:
    Student operator[] (string index) const;

    void Append(Student&);
    void Print();
    void LoadDataBaseFromFile(string);
};

#endif
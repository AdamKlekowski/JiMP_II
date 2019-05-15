#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include <vector>
#include "Student.h"
#include "Query.h"

class StudentRepository{
private:
    std::vector<Student> students;

public:
    void Append(Student&);
    void Print();
    void LoadDataBaseFromFile(string);

    std::vector<Student>FindByQuery(Query &query) const;
};

#endif
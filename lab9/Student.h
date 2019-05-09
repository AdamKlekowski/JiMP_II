#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using ::std::string;

class Student{
private:
    string id;
    string firstName;
    string lastName;
    string field;
    int studyYear;

public:
    Student();
    Student(string, string, string, string, int);

    friend std::istream& operator>> (std::istream&, Student&);
    friend std::ostream& operator<< (std::ostream &output, const Student& student);

    friend class StudentRepository;
    string GetFirstName() const;
    string GetLastName() const;
    string GetField() const;
    int GetStudyYear() const;
};

#endif
#include "Student.h"
#include <iostream>

Student::Student() {}

Student::Student(string id, string firstName, string lastName, string field, int nYear)
{
    this->id=id;
    this->firstName=firstName;
    this->lastName=lastName;
    this->field=field;
    studyYear=nYear;
}

std::ostream& operator<< (std::ostream &output, const Student& student)
{
    return output   << "{id: \"" << student.id << "\", "
                    << "firstName: \"" << student.firstName << "\", "
                    << "lastName: \"" << student.lastName << "\", "
                    << "field: \"" << student.field << "\", "
                    << "studyYear: \"" << student.studyYear << "\"}";
}

string Student::GetFirstName() const { return firstName; }
string Student::GetLastName() const { return lastName; }
string Student::GetField() const { return field; }
int Student::GetStudyYear() const { return studyYear; }
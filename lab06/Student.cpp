#include "Student.h"

Student::Student() {}

Student::Student(string id, string firstName, string lastName, string field, int nYear) : year(nYear)
{
    this->id=id;
    this->firstName=firstName;
    this->lastName=lastName;
    this->field=field;
}

istream& operator>> (istream &input, Student& student)
{
    input >> student.id >> student.firstName >> student.lastName >> student.field >> student.year;
    return input;
}

ostream& operator<< (ostream &output, const Student& student)
{
    return output   << "{id: \"" << student.id << "\", "
                    << "firstName: \"" << student.firstName << "\", "
                    << "lastName: \"" << student.lastName << "\", "
                    << "field: \"" << student.field << "\", "
                    << student.year << "}";
}
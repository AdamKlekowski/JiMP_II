#include "Student.h"

Student::Student(const std::string id, const std::string name, 
            const std::string surname, const std::string faculty) : Person(id, name, surname)
            {
                this->faculty=faculty;
            }

std::ostream& operator<< (std::ostream &output, const Student& student)
{
    return output   << "id: " << student.id << std::endl
                    << "name: " << student.name << std::endl
                    << "surname: " << student.surname << std::endl
                    << "faculty: " << student.faculty << std::endl; 
}

#include "Employee.h"

Employee::Employee(const std::string id, const std::string name, 
            const std::string surname, const double salary) : Person(id, name, surname)
            {
                this->salary=salary;
            }

std::ostream& operator<< (std::ostream &output, const Employee& Employee)
{
    return output   << "id: " << Employee.id << std::endl
                    << "name: " << Employee.name << std::endl
                    << "surname: " << Employee.surname << std::endl
                    << "salary: " << Employee.salary << std::endl; 
}

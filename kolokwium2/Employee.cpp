#include "Employee.h"

Employee::Employee() {}

Employee::Employee(std::string name, std::string surname, double salary)
{
    this->name=name;
    this->surname=surname;
    this->salary=salary;
}

std::istream& operator>> (std::istream &input, Employee &employee)
{
    input >> employee.name >> employee.surname >> employee.salary;
    return input;
}

std::ostream& operator<< (std::ostream &output, const Employee &employee)
{
    return output   << "name: " << employee.name << std::endl
                    << "surname: " << employee.surname << std::endl
                    << "salary: " << employee.salary << std::endl;
}

bool Employee::operator== (const Employee &employeeToCompare) const
{
    return salary==employeeToCompare.GetSalary();
}

std::string Employee::GetName() const { return name; }
std::string Employee::GetSurname() const { return surname; }
double Employee::GetSalary() const { return salary; }

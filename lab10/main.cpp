#include <iostream>

#include "Repository.h"
#include "Student.h"
#include "Employee.h"
#include "NotFoundException.h"
#include "IndexInUseException.h"

template <class T>
void useQuery(const ByNameQuery &query, const Repository<T> &repository)
{   
    std::vector<T> queryResult (repository.FindBy(query));

    std::cout << std::endl << "----- result of query request ----- ";
    for (auto element : queryResult)
    {
        std::cout << std::endl << element;
    }
    std::cout << "----- end of query result ----- " << std::endl << std::endl;
}

int main()
{
    //----- class Student -----
    Repository<Student> studentRepository;
    Student AGH_student("AGH01", "Adam", "Klekowski", "EAIiIB");
    Student UJ_student("UJ01", "Elon", "Musk", "FiIT");
    Student PK_student("PK01", "Steve", "Jobs", "FiIS");

    try{
        studentRepository.Append(AGH_student);
        studentRepository.Append(UJ_student);
        studentRepository.Append(PK_student);
    }
    catch (const IndexInUseException &error){
        std::cerr << error.what() << ": " << error.GetDetails() << std::endl;
    }

    try{
        std::cout << studentRepository["AGH99"] << std::endl;
    }
    catch (const NotFoundException &error){
        std::cerr << error.what() << ": " << error.GetDetails() << std::endl;
    }
    studentRepository.Print();


    //----- class Employee -----
    Repository<Employee> employeeRepository;
    Employee Google_employee("G01", "Adam", "Klekowski", 2000);
    Employee IBM_employee("IBM01", "Elon", "Musk", 11000);
    Employee ABB_employee("ABB01", "Adam", "Klekowski", 14500);

    try{
        employeeRepository.Append(Google_employee);
        employeeRepository.Append(IBM_employee);
        employeeRepository.Append(ABB_employee);
    }
    catch (const IndexInUseException &error){
        std::cerr << error.what() << ": " << error.GetDetails() << std::endl;
    }

    ByNameQuery nameQuery("Adam");
    useQuery<Employee>(nameQuery, employeeRepository); 
}
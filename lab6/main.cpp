#include <iostream>
using ::std::cin;
using ::std::cout;
using ::std::endl;

#include "Student.h"
#include "StudyYear.h"
#include "StudentRepository.h"

int main()
{
    StudentRepository repository;
    repository.LoadDataBaseFromFile("database.txt");

    repository.Print();
    
    try{
        cout << endl << "Found record: " << repository["3001"] << endl;;
    }
    catch (string exception)
    {
        cout << exception << endl;;
    }

    StudyYear year2(2);
    cout << year2 << endl;
    cout << year2++ << endl;
    cout << year2 << endl;
    cout << ++year2 << endl;

    int intStudentYear=static_cast<int>(year2);
    cout << intStudentYear;
}
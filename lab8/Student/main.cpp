#include <iostream>
using ::std::cin;
using ::std::cout;
using ::std::endl;

#include "Student.h"
#include "InvalidNameSurnameException.h"
#include "InvalidNameCharactersException.h"
#include "InvalidAgeException.h"
#include "InvalidProgramException.h"

int main()
{    
    try{
        Student firstStudent("Adam", "Klekowski", "Construction", 20);
        cout << "New object created succesfully" << endl << firstStudent << endl;
    }
    catch (const InvalidNameSurnameException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
    catch (const InvalidNameCharactersException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
    catch (const InvalidAgeException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
    catch (const InvalidProgramException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }

    try{
        Student secondStudent;
        cout << endl << "Enter data (name surname field age):" << endl;
        cin >> secondStudent;
        secondStudent.validate();
        cout << "New object created succesfully" << endl << secondStudent << endl;
    }
    catch (const InvalidNameSurnameException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
    catch (const InvalidNameCharactersException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
    catch (const InvalidAgeException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
    catch (const InvalidProgramException &error) {
        std::cerr << error.what() << ": " << error.GetInvalidData() << endl;
    }
}
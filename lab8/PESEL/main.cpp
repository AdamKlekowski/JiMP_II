#include <iostream>
using ::std::cout;
using ::std::endl;

#include <stdexcept>

#include "PESEL.h"
#include "InvalidPESELException.h"

int main()
{
    try{
        char num[]="00012070116";
        PESEL pesel(num);
        cout << "PESEL number is valid.";
    }
    catch(const InvalidPESELException &error) {
        std::cerr << error.what() << ": " << error.GetPesel() << endl;
    }
}
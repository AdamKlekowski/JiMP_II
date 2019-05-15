#include <iostream>
#include "Repository.h"
#include "NotFoundException.h"

int main()
{
    try{

    }
    catch (const NotFoundException &error){
        std::cerr << error.what() << ": " << error.GetDetails() << std::endl;
    }
}
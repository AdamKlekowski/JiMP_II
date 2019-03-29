#include<iostream>
using ::std::cout;
using ::std::endl;

#include "Martian.h"

int Martian::martianCount=0;

Martian::Martian() { martianCount++; }

Martian::~Martian() { martianCount--; }

void Martian::Attack() 
{
    if (Martian::martianCount>5)
    {
        cout << "I'm attacking" << endl;
    }
    else
    {
        cout << "I'm waiting" << endl;
    }
}
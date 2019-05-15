#include "PESEL.h"
#include "InvalidPESELException.h"

#include <ostream>
using ::std::ostream;

#include <string.h>

PESEL::PESEL(char *newValue) 
{
    memcpy(value, newValue, 12);
    if(!validatePESEL(newValue)) throw InvalidPESELException(*this);
}

#include <iostream>

bool PESEL::validatePESEL(const char *value) 
{
    short tmp=(value[0]-48);
    tmp+=(value[1]-48)*3;
    tmp+=(value[2]-48)*7;
    tmp+=(value[3]-48)*9;
    tmp+=(value[4]-48);
    tmp+=(value[5]-48)*3;
    tmp+=(value[6]-48)*7;
    tmp+=(value[7]-48)*9;
    tmp+=(value[8]-48);
    tmp+=(value[9]-48)*3;

    tmp=tmp%10;
    tmp=10-tmp;
    tmp=tmp%10;
    if (tmp==(value[10]-48)) {return true;}
    else {return false;}
}

ostream& operator<< (ostream &output, const PESEL& pesel)
{
    for(int i=0; i<12; i++)
    {
        output << (pesel.value)[i];
    }
    return output;
}
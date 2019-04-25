#ifndef PESEL_H
#define PESEL_H

#include <ostream>
using ::std::ostream;

class PESEL{
private:
    char value[12];

public:
    PESEL(char*);
    bool validatePESEL(const char*);

    friend ostream& operator<< (ostream &output, const PESEL& pesel);
};

#endif
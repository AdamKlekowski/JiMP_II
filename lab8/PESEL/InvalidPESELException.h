#ifndef INVALID_PESEL_EXCEPTION_H
#define INVALID_PESEL_EXCEPTION_H

#include <stdexcept>
using ::std::invalid_argument;

#include "PESEL.h"

class InvalidPESELException : public invalid_argument{
private:
    PESEL wrongPesel;

public:
    InvalidPESELException(const PESEL &pesel) : invalid_argument{"Wrong PESEL number"}, 
                                                wrongPesel(pesel) {}
    PESEL GetPesel() const { return wrongPesel; }
};

#endif
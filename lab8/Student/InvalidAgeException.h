#ifndef INVALID_AGE_H
#define INVALID_AGE_H

#include <stdexcept>
using ::std::invalid_argument;

class InvalidAgeException : public invalid_argument{
private:
    int invalidData;

public:
    InvalidAgeException(const int &age) : invalid_argument{"Invalid age"}
    {
        invalidData=age;
    }
    int GetInvalidData() const { return invalidData; }
};

#endif
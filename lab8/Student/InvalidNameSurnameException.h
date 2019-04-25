#ifndef INVALID_NAME_SURNAME_H
#define INVALID_NAME_SURNAME_H

#include <stdexcept>
using ::std::invalid_argument;

#include <string>
using ::std::string;

class InvalidNameSurnameException : public invalid_argument{
private:
    string invalidData;

public:
    InvalidNameSurnameException(const string &name, const string &surname) : invalid_argument{"Invalid name or surname"}
    {
        invalidData=name + " " + surname;
    }
    string GetInvalidData() const { return invalidData; }
};

#endif
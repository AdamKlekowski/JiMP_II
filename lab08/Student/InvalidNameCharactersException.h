#ifndef INVALID_NAME_CHARACTERS_H
#define INVALID_NAME_CHARACTERS_H

#include <stdexcept>
using ::std::invalid_argument;

#include <string>
using ::std::string;

class InvalidNameCharactersException : public invalid_argument{
private:
    string invalidData;

public:
    InvalidNameCharactersException(const string &name, const string &surname) : invalid_argument{"Invalid name characters"}
    {
        invalidData=name + " " + surname;
    }
    string GetInvalidData() const { return invalidData; }
};

#endif
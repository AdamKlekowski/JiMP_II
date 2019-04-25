#ifndef INVALID_PROGRAM_H
#define INVALID_PROGRAM_H

#include <stdexcept>
using ::std::invalid_argument;

#include <string>
using ::std::string;

class InvalidProgramException : public invalid_argument{
private:
    string invalidData;

public:
    InvalidProgramException(const string &field) : invalid_argument{"Invalid program"}
    {
        invalidData=field;
    }
    string GetInvalidData() const { return invalidData; }
};

#endif
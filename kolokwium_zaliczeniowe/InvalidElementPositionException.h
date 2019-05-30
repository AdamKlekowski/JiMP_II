#ifndef INVALID_ELEMENT_POSITION_EXCEPTION_H
#define INVALID_ELEMENT_POSITION_EXCEPTION_H

#include <stdexcept>

class InvalidElementPositionException : public std::out_of_range{
private:
    std::string wrongIndex;

public:
    InvalidElementPositionException(int index) : out_of_range{"Index is out of range"}
    {
        wrongIndex= std::to_string(index);
    }
    std::string GetDetails() const { return wrongIndex; }
};

#endif
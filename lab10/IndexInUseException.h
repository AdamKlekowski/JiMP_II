#ifndef INDEX_IN_USE_EXCEPTION_H
#define INDEX_IN_USE_EXCEPTION_H

#include <stdexcept>
#include <string>

class IndexInUseException : public std::invalid_argument{
private:
    std::string details;
public:
    IndexInUseException(const std::string details) : invalid_argument("Index is already is use")
    {
        this->details=details;
    }
    std::string GetDetails() const { return details; }
};

#endif
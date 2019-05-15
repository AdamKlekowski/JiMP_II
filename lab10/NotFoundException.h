#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H

#include <stdexcept>
#include <string>

class NotFoundException : public std::invalid_argument{
private:
    std::string details;
public:
    NotFoundException(const std::string details) : invalid_argument("Seeking index was not found")
    {
        this->details=details;
    }
    std::string GetDetails() const { return details; }
};

#endif
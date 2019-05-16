#ifndef BY_NAME_H
#define BY_NAME_H

#include <string>

class ByNameQuery{
private:
    std::string pattern;
public:
    ByNameQuery(std::string seekingName) { pattern=seekingName; }

    template <class T>
    bool Accept(const T &person) const { return person.GetName()==pattern; }
};

#endif
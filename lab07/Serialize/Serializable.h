#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <vector>
using ::std::vector;

#include "Serializer.h"

class Serializable{
public:
    virtual void Serialize (Serializer *, vector<string>) = 0;
};

#endif
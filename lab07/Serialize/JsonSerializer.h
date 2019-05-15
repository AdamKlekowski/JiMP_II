#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "Serializable.h"

class JsonSerializer : public Serializable{
public:
    void Serialize (Serializer *, vector<string>);
};

#endif
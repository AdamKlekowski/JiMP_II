#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>
using ::std::string;

class Serializer{
public:
    string serializedObject;

    Serializer() { serializedObject=""; }

    friend class JsonSerializer;
    friend class XmlSerializer;
};

#endif
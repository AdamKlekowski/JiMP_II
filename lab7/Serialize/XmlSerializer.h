#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include "Serializable.h"

class XmlSerializer : public Serializable{
public:
    void Serialize (Serializer *, vector<string>);
};

#endif
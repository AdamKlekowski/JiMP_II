#include "XmlSerializer.h"

void XmlSerializer::Serialize(Serializer *serializer, vector<string> vector) 
{
    serializer->serializedObject="{\n";
    for (int i=0; i<vector.size(); i+=2)
    {
        serializer->serializedObject+="\t<";
        serializer->serializedObject+=vector.at(i);
        serializer->serializedObject+=">";
        serializer->serializedObject+=vector.at(i+1);
        serializer->serializedObject+="</";
        serializer->serializedObject+=vector.at(i);
        serializer->serializedObject+=">\n";
    }
    serializer->serializedObject+="}\n";
}
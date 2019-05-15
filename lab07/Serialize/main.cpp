#include <iostream>
using ::std::cout;
using ::std::endl;

#include "ExampleClass.h"
#include "JsonSerializer.h"
#include "XmlSerializer.h"
#include "Serializer.h"

int main()
{
    Serializer *serializer=new Serializer();
    vector<string> v= {"name", "Adam", "age", "20"};

    cout<<"Json:" << endl;
    Serializable *serializable = new JsonSerializer();
    serializable->Serialize(serializer, v);
    cout << serializer->serializedObject;

    cout<<"Xml:" << endl;;
    serializable = new XmlSerializer();
    serializable->Serialize(serializer, v);
    cout << serializer->serializedObject;
}
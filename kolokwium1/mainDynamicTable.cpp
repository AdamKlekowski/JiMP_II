#include<iostream>
using ::std::cout;
using ::std::endl;

#include<string>
using ::std::string;

#include "DynamicTable.h"

int main()
{
    DynamicTable *myTable = new DynamicTable(3);
    for (int j=0; j<15; j++)
    {
        myTable->Add(j);  
    }

    cout << "Po dodaniu 15 elementów: "<< endl;
    myTable->Print();
    cout << endl << endl;

    cout << "Element o indeksie 7: " << myTable->Get(7) << endl;
    myTable->Set(-10,7);
    cout << "Element o indeksie 7 po zmianie na -10: " << myTable->Get(7) << endl;
    cout << endl;


    try{
        cout << "Zmiana elemntu spoza zakresu:" << endl;
        myTable->Set(100,100);
    }
    catch (string exception)
    {
        cout << "Wyjątek: " << exception << endl;
    }

}
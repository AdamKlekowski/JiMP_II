#include<iostream>
using ::std::cout;

#include<string>
using ::std::string;

#include "DynamicTable.h"

void DynamicTable::Resize(int newSize) 
{
    double *newTable = new double[newSize];
    if (table!=NULL)
    {
        for (int i=0; i<=last; i++)
        {
            newTable[i]=table[i];
        }
        delete table;
    }
    table=newTable;
    length=newSize;
}

DynamicTable::DynamicTable() 
{
    table=NULL;
    length=0;
    last=-1;
    Resize(10);
}

DynamicTable::DynamicTable(int initLength) 
{
    table=NULL;
    length=0;
    last=-1;
    Resize(initLength);
}

DynamicTable::~DynamicTable() 
{
    delete table;
}

void DynamicTable::Add(double element) 
{
    if (last+1>=length)
    {
        Resize(length+10);
    }
    last++;
    table[last]=element;
}

double DynamicTable::Get(int index) 
{
    if (index>last)
    {
        string exception="out_of_range";
        throw exception;
    }
    return table[index];
}

void DynamicTable::Set(double element, int index) 
{
    if (index>last)
    {
        string exception="out_of_range";
        throw exception;
    }
    table[index]=element;
}

void DynamicTable::Print() 
{
    for (int i=0; i<=last; i++)
    {
        cout << table[i] << " ";
    }
}
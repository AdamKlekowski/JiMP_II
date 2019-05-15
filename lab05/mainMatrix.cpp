#include<iostream>
using ::std::cout;
using ::std::endl;

#include "Matrix.h"

int main()
{
    Matrix m1("[1i2 2; 3 4]");
    m1.printingMatrix();
    cout << endl;


    Matrix m2("[5i8 6i1; 7 8]");
    m2.printingMatrix();
    cout << endl;
    
    
    try{
        Matrix result=m1+m2;
        result.printingMatrix();
        cout << endl;
    }
    catch (string exception)
    {
        cout<<"Exception: "<< exception << endl;
    }

    try{
        m1.setElementInMatrix(1, 3, 0);
        m1.printingMatrix();
    }
    catch (string exception)
    {
        cout<<"Exception: "<< exception << endl;
    }
}
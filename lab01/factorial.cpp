#include<iostream>
using ::std::cout;
using ::std::endl;

int factorialIte(int n)
{
    int result=1;
    for (int i=1; i<=n; i++)
    {
        result*=i;
    }
    return result;
}

int factorialRec(int n)
{
    if (n==1 || n==0) return 1;
    return factorialRec(n-1)*n;
}

int main()
{
    cout << "0!=" << factorialRec(0) << endl;
    cout << "1!=" << factorialRec(1) << endl;
    cout << "6!=" << factorialRec(6) << endl << endl;

    cout << "0!=" << factorialIte(0) << endl;
    cout << "1!=" << factorialIte(1) << endl;
    cout << "6!=" << factorialIte(6) << endl;
}
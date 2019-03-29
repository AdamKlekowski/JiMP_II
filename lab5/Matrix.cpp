#include<iostream>
using ::std::cout;
using ::std::endl;

#include "Matrix.h"

Matrix::Matrix() {}

void Matrix::allocateMemory(int n_rows, int n_columns)
{
    this->n_rows=n_rows;
    this->n_columns=n_columns;

    array = new complex<double> * [n_rows];

    for (int i = 0; i<n_rows; i++)
        array[i] = new complex<double> [n_columns];
}

Matrix::Matrix(int n_rows, int n_columns)
{
    allocateMemory(n_rows, n_columns);
}

vector<string> Matrix::splitMatlabNotatation(string MatlabNotation)
{
    vector<string> result;
    int rows=1, columns=1;

    string tmp="";
    for (char letter : MatlabNotation)
    {
        if(letter=='[') {}
        else if(letter==' ') 
        { 
            result.push_back(tmp);
            columns++;
            tmp="";
        }
        else if (letter==';') { rows++; }
        else if (letter==']') {}
        else
        {
            tmp.push_back(letter);
        }
    }
    result.push_back(tmp);

    n_rows=rows;
    n_columns=columns/rows;
    return result;
}

vector<complex<double>> Matrix::stringToComplex (vector<string> v)
{
    vector<complex<double>> result;
    string real, imaginary;
    short flag;
    
    double re, im;
    complex<double> complexNum;

    for(auto element : v)
    {
        flag=0; real=""; imaginary="";
        for(char letter : element)
        {
            if (letter=='i') { flag=1; }
            else if (flag==0) { real.push_back(letter); }
            else { imaginary.push_back(letter); }
        }
        re=std::atof(real.c_str());
        im=std::atof(imaginary.c_str());

        complexNum.real(re);
        complexNum.imag(im);

        result.push_back(complexNum);
    }

    return result;
}

Matrix::Matrix(string MatlabNotation)
{
    vector<string> splittedNotation=splitMatlabNotatation(MatlabNotation);
    vector<complex<double>> complexVector=stringToComplex (splittedNotation);
    allocateMemory(n_rows, n_columns);

    for (int i=0; i<n_rows; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            array[i][j]=complexVector.at(i*n_columns+j);
        }
    }
}

Matrix::Matrix(const Matrix &originalMatrix)
{
    n_rows=originalMatrix.n_rows;
    n_columns=originalMatrix.n_columns;
    for (int i = 0; i<n_rows; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            array[i][j]=originalMatrix.array[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i<n_rows; i++)
        delete [] array[i];
    delete [] array;
    array=NULL;
}

void Matrix::printingMatrix ()
{
    for (int i = 0; i<n_rows; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            cout.width(8);
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

complex<double> Matrix::getElementInMatrix(int x, int y)
{
    if(x-1>=n_rows || y-1>=n_columns)
    {
        string exception = "inccorect coordinates";
        throw exception;
    }
    return array[x-1][y-1];
}

void Matrix::setElementInMatrix(int x, int y, complex<double> value)
{
    if(x-1>=n_rows || y-1>=n_columns)
    {
        string exception = "inccorect coordinates";
        throw exception;
    }
    array[x-1][y-1]=value;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    if (m1.n_columns!=m2.n_columns || m1.n_rows!=m2.n_rows)
    {
        string exception ="incorrect dimensions";
        throw exception;
    }

    Matrix result(m1.n_rows, m1.n_columns);
    
    for (int i=0; i<m1.n_rows; i++)
    {
        for (int j=0; j<m1.n_columns; j++)
        {
            result.array[i][j]=m1.array[i][j] + m2.array[i][j];
        }   
    }
    return result;
}

Matrix operator-(const Matrix &m1, const Matrix &m2)
{
    if (m1.n_columns!=m2.n_columns || m1.n_rows!=m2.n_rows)
    {
        string exception ="incorrect dimensions";
        throw exception;
    }

    Matrix result(m1.n_rows, m1.n_columns);
    
    for (int i=0; i<m1.n_rows; i++)
    {
        for (int j=0; j<m1.n_columns; j++)
        {
            result.array[i][j]=m1.array[i][j] - m2.array[i][j];
        }   
    }
    return result;
}

Matrix operator *(const Matrix& m1, const complex<double>& comlexNum)
{
    Matrix result(m1.n_rows, m1.n_columns);
    
    for (int i=0; i<m1.n_rows; i++)
    {
        for (int j=0; j<m1.n_columns; j++)
        {
            result.array[i][j]=m1.array[i][j] *comlexNum;
        }   
    }
    return result;
}
#include <complex>
using ::std::complex;

#include<vector>
using ::std::vector;

#include <string>
using ::std::string;

class Matrix{
private:
    complex<double> **array;
    int n_rows; 
    int n_columns;

    void allocateMemory(int, int);
    vector<string> splitMatlabNotatation(string);
    vector<complex<double>> stringToComplex (vector<string>);

public:
    Matrix();
    Matrix(int, int);
    Matrix(string);
    Matrix(const Matrix&);
    ~Matrix();

    void printingMatrix();
    complex<double> getElementInMatrix(int, int);
    void setElementInMatrix(int, int, complex<double>);

    friend Matrix operator +(const Matrix&, const Matrix&);
    friend Matrix operator -(const Matrix&, const Matrix&);
    friend Matrix operator *(const Matrix&, const complex<double>&);
};
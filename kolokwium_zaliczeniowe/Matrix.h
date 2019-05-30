#ifndef MATRIX_H
#define MATRIX_H

#include "InvalidElementPositionException.h"

template <typename T>
class Matrix{
private:
    T ** matrix;
    int n_rows;
    int n_columns;

public:
    Matrix(int rows, int columns)
    {
        n_rows=rows;
        n_columns=columns;

        matrix = new T * [rows];

        for (int i = 0; i<columns; i++)
        {
            matrix[i] = new T [columns];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i<n_rows; i++)
        {
            delete [] matrix[i];
        }
        delete [] matrix;      
    }

    void setAt(int rowIndex, int columnIndex, T t)
    {
        if(rowIndex>n_rows) throw InvalidElementPositionException(rowIndex);
        else if(columnIndex>n_columns) throw InvalidElementPositionException(columnIndex);
        matrix[rowIndex][columnIndex]=t;
    }
};

#endif
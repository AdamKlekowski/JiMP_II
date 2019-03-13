#include <iostream>

using namespace std;

int **Array2D(int n_rows, int n_columns)
{
    int ** array = new int * [n_rows];

    for (int i = 0; i<n_rows; i++)
    array[i] = new int [n_columns];

    for (int i = 0; i<n_rows; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            array[i][j]=i*n_columns+j+1;
        }
    }
    return array;
}

void PrintingArray2D(int**array, int n_rows, int n_columns)
{
    for (int i = 0; i<n_rows; i++)
    {
        for (int j=0; j<n_columns; j++)
        {
            cout.width(3);
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteArray2D(int**array, int n_rows, int n_columns)
{
    for (int i = 0; i<n_rows; i++)
        delete [] array[i];
    delete [] array;    
}

int main()
{
    int n_rows, n_columns;
    cout << "Liczba wierszy: ";
    cin >> n_rows;
    cout << "Liczba kolumn:";
    cin >> n_columns;
    int ** array2D=Array2D(n_rows,n_columns);
    PrintingArray2D(array2D, n_rows, n_columns);
    DeleteArray2D(array2D, n_rows, n_columns);
}
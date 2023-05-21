#ifndef MATRIX_H
#define MATRIX_H

#include<bits/stdc++.h>
using namespace std;

template <class T>

class Matrix
{
private:
    int rows, cols;
    T info;
    T **arr;
    static int cnt;

public:
    //parametrized constructor
    Matrix(int rows=0, int cols=0)
    {
        this-> rows = rows;
        this-> cols = cols;
        //this-> info = info;

        arr = new T *[rows];
        for(int count=0 ; count < rows ; count++)
        {
            arr[count] = new T [cols];
        }
    }



    //a setter to set info
    void setInfo(T i)
    {
        info = i;
    }

    //setter to set rows num
    void setRow(int row)
    {
        rows = row;
    }

    //setter to set cols num
    void setCol(int col)
    {
        cols = col;
    }

    //getter to get rows num
    int getRow()
    {
        return rows;
    }

    //getter to get cols num
    int getCol()
    {
        return cols;
    }


    //a function that transpose the matrix
    void MatrixTranspose(Matrix<T> obj)
    {
        Matrix m(rows, cols);

        for(int i=0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                m.arr[j][i] = obj.arr[i][j];
            }
        }

        for(int i=0 ; i < cols ; i++)
        {
            for(int j = 0 ; j < rows ; j++)
            {
                cout << m.arr[i][j] << " ";
            }
            cout << endl;
        }


    }

    //operator overloading for + to add two matrices
    Matrix<T> operator+(Matrix<T> &A)
    {
        Matrix m(rows, cols);
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                m.arr[i][j] = arr[i][j] + A.arr[i][j];
            }
        }

        cout << endl;
        return m;
    }

    //operator overloading for - to subtract two matrices
    Matrix<T> operator-(Matrix<T> &A)
    {
        Matrix m(rows, cols);
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                m.arr[i][j] = arr[i][j] - A.arr[i][j];
            }
        }

        cout << endl;
        return m;
    }

    //operator overloading for * to multiply two matrices
    Matrix<T> operator*(Matrix<T> &A)
    {
        int sum = 0;
        Matrix m(rows, cols);

        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < A.cols ; j++)
            {
                for(int a = 0 ; a < cols ; a++)
                {
                    sum += (arr[i][a] * A.arr[a][j]);
                }
                m.arr[i][j] = sum;
                sum = 0;
            }
        }

        cout << endl;
        return m;

    }


    //a destructor that deletes the dynamic 2d array
    ~Matrix()
    {
        for(int cnt=0 ; cnt < rows ; cnt++)
        {
            delete[] arr[cnt] ;
        }
        delete[] arr;
    }



    template <class t>
    friend istream& operator>>(istream &input, Matrix <t> &obj);

    template <class t>
    friend ostream& operator<<(ostream &output, const Matrix <t> &obj);

};

//initializing the static variable cnt with 0
template <class t>
int Matrix<t>::cnt=0;

//operator overloading for extraction operator
template <class t>
istream& operator>>(istream &input, Matrix <t> &obj)
{
    obj.cnt++;
    cout << "Enter the size of the matrix number " << obj.cnt << " :" << endl;
    cout << "Rows: ";
    cin >> obj.rows;
    cout << "Cols: ";
    cin >> obj.cols;

    obj.arr = new t *[obj.rows];
    for(int cnt=0 ; cnt < obj.rows ; cnt++)
    {
        obj.arr[cnt] = new t [obj.cols];
    }

    for(int i = 0 ; i < obj.rows ; i++)
        {
            for(int j = 0 ; j < obj.cols ; j++)
            {
                cout << "Enter the [" << i <<"][" << j << "] index: ";
                input >> obj.arr[i][j];
            }
        }

    return input;
}

//operator overloading for insertion operator
template <class t>
ostream& operator<<(ostream &output, const Matrix <t> &obj)
{
    for(int cnt=0 ; cnt < obj.rows ; cnt++)
        {
            for(int i = 0 ; i < obj.cols ; i++)
            {
                output <<obj.arr[cnt][i] << " ";
            }
            output << endl;
        }

    return output;
}


#endif // MATRIX_H

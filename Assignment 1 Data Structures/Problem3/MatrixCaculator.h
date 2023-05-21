#ifndef MATRIXCACULATOR_H
#define MATRIXCACULATOR_H
#include<bits/stdc++.h>
#include"Matrix.h"
using namespace std;

template <class T>
class MatrixCaculator
{
public:
    MatrixCaculator(){} //a default constructor

    //function menu that shows the user the choices he would like to choose any of them
    void menu()
    {
        cout << "Welcome to our Matrix Calculator" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "1- Perform Matrix Addition" << endl;
        cout << "2- Perform Matrix Subtraction" << endl;
        cout << "3- Perform Matrix Multiplication" << endl;
        cout << "4- Matrix Transpose" << endl;
        cout << "5- Exit the program" << endl;

        Matrix<T> obj1, obj2; //objects of the first class Matrix
        int choice;
        cout << endl;

        cin >> obj1;
        cout << endl;
        cin >> obj2;
        while(true)
        {
            cout << "--------------------------------" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;



            if(choice == 1)
            {
                if(obj1.getRow()==obj2.getRow() && obj1.getCol()==obj2.getCol())
                {
                    cout << endl;
                    cout << "The result of adding is: " << endl;
                    cout << obj1 + obj2 << endl; //adding the two matrices
                }

                else
                {
                    cout << endl;
                    cout << "The two matrices can't be added" << endl;

                }

            }

            else if(choice == 2)
            {
                if(obj1.getRow()==obj2.getRow() && obj1.getCol()==obj2.getCol())
                {
                    cout << endl;
                    cout << "The result of subtracting is: " << endl;
                    cout << obj1 - obj2 << endl; //subtracting the two matrices
                }

                else
                {
                    cout << endl;
                    cout << "The two matrices can't be subtracted" << endl;
                }

            }

            else if(choice == 3)
            {

                if(obj1.getCol() == obj2.getRow())  //to multiply 2 matrices, the number of cols in the first matrix
                {                                  //must = the number of rows in the second one
                    cout << endl;
                    cout << "The result of multiplying is: ";
                    cout << obj1 * obj2 <<endl; //multiplying the two matrices
                }

                else
                {
                    cout << endl;
                    cout << "The two matrices can't be multiplied" << endl;
                }
            }

            else if(choice == 4)
            {
                int option;
                cout << "First matrix or second one you want it transposed? (Enter 1 or 2): ";
                cin >> option;
                if(option == 1)
                {
                    cout << endl;
                    cout << "The first matrix transposed: " << endl;
                    obj1.MatrixTranspose(obj1); //calling the function MatrixTranspose
                }

                else if(option == 2)
                {
                    cout << endl;
                    cout << "The second matrix transposed: " << endl;
                    obj2.MatrixTranspose(obj2);
                }



            }

            else if(choice == 5)
            {
                cout << endl;
                cout << "You have exited the program" << endl;
                break;
            }
        }
    }
};

#endif // MATRIXCACULATOR_H

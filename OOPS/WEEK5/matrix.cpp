//Name: Alwin Crasta
//Regno: 210970125
//Date: 07-01-2022
//Program: Write a C++ program to create a class called Matrix using 2-Dimensional array of integers
#include<iostream>
using namespace std;

class Matrix {
    int m,n;
    int arr[20][20];

    public:
        void insert() {
            cout<<"Enter value for row:";
            cin>>n;

            cout<<"Enter value for column:";
            cin>>m;
            cout<<"Enter Matrix values:";
            for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                            cin>>arr[i][j];
                    }
            }

        }
        friend void display(Matrix mat) {
            cout<<endl;
            for(int i=0;i<mat.n;i++) {
                    for(int j=0;j<mat.m;j++) {
                            cout<<mat.arr[i][j]<<"  ";
                    }
                    cout<<endl;
            }
        }
	
	int operator == (Matrix m2) {
            	if(n != m2.n || m != m2.m) {
                	return 0;
		} else {
			return 1;
		}
	}
        Matrix operator + (Matrix m2) {
                Matrix mat;
                mat.n = n;
                mat.m = m;

                for(int i=0;i<n;i++) {
                        for(int j=0;j<m;j++) {
                                mat.arr[i][j] = arr[i][j] + m2.arr[i][j];
                        }
                        cout<<endl;
                }
                cout<<"\nAddition of matrix:";
                display(mat);
                return mat;
        }
    
        Matrix operator - (Matrix m2) {
                Matrix mat;
                mat.n = n;
                mat.m = m;

                for(int i=0;i<n;i++) {
                        for(int j=0;j<m;j++) {
                                mat.arr[i][j] = arr[i][j] - m2.arr[i][j];
                        }
                        cout<<endl;
                }
                cout<<"\nSubraction of matrix:";
                display(mat);
                return mat;
        }
};

int main() {
    	system("clear");

    	Matrix m1,m2;
    	m1.insert();
    	m2.insert();

    	Matrix m3;
    	Matrix m4;

	if(m1 == m2) {
    		m3 = m1 + m2;
    		m4 = m1 - m2;
	} else {
		cout<<"Matrix cannot be added or subracted";
	}

    	cout<<endl;
    	return 0;
}

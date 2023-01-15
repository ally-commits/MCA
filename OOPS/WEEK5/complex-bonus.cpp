//Name: Alwin Crasta
//Regno: 210970125
//Date: 07-01-2022
//Program Name: Write a C++ program to perform addition and subtraction on two complex numbers using operator overloading using member functions.

#include<iostream>
using namespace std;


class Complex {
	int img, real;
	public:
		void insert() {
			cout<<"\nEnter real and img numbers:";
			cin>>real>>img;
		}		
			
		void display() {
			cout<<"\nReal Number:"<<real;
			cout<<"\nImg Number:"<<img;
		}
		
		Complex operator + (Complex c1) {
			Complex newC;
			newC.img = img + c1.img;
			newC.real = real + c1.real;
		
			return newC;
		}
		
		Complex operator - (Complex c1) {
			Complex newC;
			newC.img = img - c1.img;
			newC.real = real - c1.real;
		
			return newC;
		}

};
int main() {
	Complex c1,c2,c3,c4;
	
	system("clear");
	c1.insert();
	c2.insert();

	c3 = c1 + c2;
	c4 = c1 - c2;
	
	cout<<"\bAddition:";	
	c3.display();
	cout<<"\nSubraction";
	c4.display();
	
	cout<<endl;

}

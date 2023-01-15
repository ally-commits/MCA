//Name: Alwin Crasta
//RegNo: 210970125
//Date: 14-JAN-2022

#include<iostream>
using namespace std;

class Shape {
	protected:
		int var_a,var_b;
	public:
		Shape(){ }

		Shape(int x,int y) {
			var_a=x;
			var_b=y;
		}
		virtual void getArea() {
			cout<<"BASE CLASS GET AREA";
		}
};

class Triangle : public Shape {
	public:
		Triangle(int x,int y) : Shape(x,y) {	}
		void getArea() {
			float value =(float) 0.5 * var_a * var_b;
			cout<<"\nArea of Triangle:"<<value;
		}

};


class Rectangle : public Shape {
	public:
		Rectangle(int x,int y) : Shape(x,y) {}
		void getArea() {
			int value = var_a * var_b;
			cout<<"\nArea of Rectangle:"<<value;
		}
};

int main() {
	system("clear");

	int x,y;
	cout<<"Enter 2 value:";
	cin>>x>>y;

	Shape *s;

	Triangle t(x, y);	
	s = &t;
	s->getArea();
	
	Rectangle r(x, y);
	s = &r;
	s->getArea();

	cout<<endl;	
	return 0;
}

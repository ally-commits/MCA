#include<iostream>
using namespace std;

class Base {
	int a;
	public:
		virtual void accept() {
			cout<<"\nBASE ACCEPT CLASS";
		}
		void display() {
			cout<<"\nBASE DISPLAY CLASS";
		}
};
class Derived :virtual public Base {
	public:
		void accept() {
			cout<<"\nDEREIVED ACCEPT CLASS";
		}
		void display() {
			cout<<"\nDERIVED DISPLAY CLASS";
		}
	
};

int main() {
	Base *b;
	Derived d;
	
	b = &d;
	d.accept();

	b->accept();
	cout<<endl;
}

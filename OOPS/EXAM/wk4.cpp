#include<iostream>
using namespace std;

class One {
	public:
		int a;
		One() {
			a =10;
			cout<<"\nSINGLE CONS";
		}
		One(int x) {
			a = x;
			cout<<"\nPARAMETERIZED CONS";
		}
		One(One &o) {
			a=o.a;
			cout<<"\nCOPY CONS";
		}
		friend void display(One &o);
		
		void insert(int x) {
			cout<<"\nSINGLE PARAMETER";
		}
		void insert(int x,int y) {
			cout<<"\n2 PAPRAMTER";
		}
};

void display(One &o) {
	cout<<"\nA="<<o.a;
	o.a = 20;
}
int main() {
	One o;
	One o1(200);
	One o2(o1);
	display(o1);
	display(o2);


	//o.insert(10);
	//o.insert(10,20);
	//display(o);
	
	//cout<<"\nA="<<o.a;
	cout<<endl;
}

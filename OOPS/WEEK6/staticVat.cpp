#include<iostream>
using namespace std;

class Var {
	static int a;
	int uniqueId;
	public:
		Var() {
			uniqueId = 1000 + a;
			a++;
		}
		void display() {
			cout<<"\nV Value:"<<uniqueId;
		}
};
int Var::a;

int main() {
	Var v1,v2,v3;
	v1.display();
	v2.display();
	v3.display();

	cout<<endl;
}

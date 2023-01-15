#include<iostream>
using namespace std;

class Matrix {
	int m;
	public:
		friend int operator * (int val,Matrix m) {
			cout<<val;
		}
		Matrix operator + (Matrix m1) {
			return Matrix();
		}
};
int main() {
	Matrix m1,m2,m3;
	int val = 10;
	
	m3 = val * m1 + m2;
	return 0;
}

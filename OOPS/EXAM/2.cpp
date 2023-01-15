#include<iostream>
using namespace std;


int main() {
	int n;
	cout<<"Enter value for n";
	
	cin>>n;
	
	for(int i=2;i<n;i++) {
		int div = 0;
		for(int j=2;j<i;j++) {
			if(i % j == 0 && j != i) 
				div = 1;
		}
		if(div == 0)
			cout<<i<<"  ";
	}
	cout<<endl;
}

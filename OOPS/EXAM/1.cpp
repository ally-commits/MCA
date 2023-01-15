#include<iostream>
using namespace std;

int main(){
	int n;
	int arr[10][10];
	cout<<"Enter n value:";
	cin>>n;
	
	for(int i=1;i<=n;i++) {
		for(int j=0;j<n-i;j++) {
			cout<<"  ";
		}
		for(int j=0;j<i;j++) {
			int printVal;
			if(i == 1 || i == 2 || j == 0 || j == i-1)
				printVal = 1;
			else
				printVal = arr[i-1][j] + arr[i-1][j-1];

			arr[i][j] = printVal;
			cout<<"   "<<printVal;
		}
		cout<<endl;
	}
	cout<<endl;
}

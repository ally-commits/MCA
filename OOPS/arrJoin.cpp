#include<iostream>
using namespace std;

int main() {
	int n,m,count=0;
	int arr1[10],arr2[10],newArr[10];
		
	cout<<"Enter first array size:";
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr1[i];

	
	cout<<"Enter second array size:";
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>arr2[i];
	
	
	for(int i=0;i<n;i++) {
		newArr[count] = arr1[i];
		count++;
	}
	
	for(int i=0;i<m;i++) {
		newArr[count] = arr2[i];
		count++;
	}

	cout<<"\n NEW ARRAY";
	for(int i=0;i<count;i++)
		cout<<newArr[i]<<" ";

	cout<<endl;
	return 0;
	
}

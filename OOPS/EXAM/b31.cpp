#include<iostream>
#include<math.h>
using namespace std;


int main() {
	int arr[10],n;
	cout<<"n value:";
	cin>>n;
	cout<<"Array value:";
	for(int i=0;i<n;i++) 
		cin>>arr[i];
	
	float mean=0,sd=0,var=0;
	for(int i=0;i<n;i++)
		mean+=arr[i];
	mean = (float) mean / n;
	
	for(int i=0;i<n;i++) {
		float val = arr[i] - mean;
		var += pow(val,2);
	}
	var = var / n;
	
	cout<<"\nMean:"<<mean;
	cout<<"\nStandard D:"<<sqrt(var);
	cout<<"\nVariance:"<<var;
		
	cout<<endl;
}

#include<iostream>
using namespace std;

int main() {
	int n=5,m=8;
	int choice;
	int arr[5][8][2];
	
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) {
			arr[i][j][0] = 0;
			arr[i][j][1] = 0;
		}


	do {
		cout<<"\n1.INSERT";
		cout<<"\n2.DISPLAY";
		cout<<"\n3.EXIT";	
		cout<<"\nEnter Choice:";
		cin>>choice;
		switch(choice) {
			case 1: {
				int nVal,mVal;
				cout<<"Enter Floor Val & Room Number:";
				cin>>nVal>>mVal;
				cout<<"Enter adults:";
				cin>>arr[nVal][mVal][0];
				cout<<"Enter Children:";
				cin>>arr[nVal][mVal][1];
		
				break;
			}
		
			case 2: {
				int total=0,tAdult=0,tChildren=0;
				for(int i=0;i<n;i++){
					int t=0,tA=0,tC=0;
					for(int j=0;j<m;j++) {
						t+=arr[i][j][0] + arr[i][j][1];
						tA+=arr[i][j][0];
						tC+=arr[i][j][1];
					}
					total+=t;
					tAdult+=tA;
					tChildren+=tC;
					cout<<"\n------------------------------------";
					cout<<"\nTotal Floor wise occupancy ="<<t;
					cout<<"\nTotal Floor wise adult occupancy="<<tA;
					cout<<"\nTotal Floor wise child occupancy="<<tC;
				}
				cout<<"\n";	
				cout<<"\n------------------------------------";
				cout<<"\nTotal Number of occupants ="<<total;
				cout<<"\nTotal Number of adults ="<<tAdult;
				cout<<"\nTotal Number of children ="<<tChildren;
				break;
			}	
		}
	}while(choice != 3);
}

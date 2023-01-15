#include<iostream>
using namespace std;

void insert(arr[10][][]) {
	int floor,room;
	cout<<"Enter floor";
	cin>>floor;
	cout<<"Enter Room";
	cin>>room;

	cout<<"Enter no of adults:";
	cin>>arr[floor][room][0];
	cout<<"Enter no of children:";
	cin>>arr[floor][room][1];
}

int main() {
	int n=5,m=8,k=2;
	int arr[n][m][k];
	
	int choice = 3;
	
	do {
		cout<<\n"Enter choice";
		cin>>choice;

		switch(choice) {
			case 1:
				inserrt(arr);
		}

	} while(choice != 10);

}

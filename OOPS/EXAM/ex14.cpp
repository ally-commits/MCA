#include<iostream>
using namespace std;

class Array {
	int n,arr[20];
	public:
		void inputArray() {
			cout<<"Enter n:";
			cin>>n;
			cout<<"Array Elements:";
			for(int i=0;i<n;i++) {
				cin>>arr[i];
			}
		}
		void display() {
			cout<<"\nArray Elements:";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
		}
		void largest() {
			int max=arr[0];
			for(int i=0;i<n;i++) {
				if(arr[i] > max) {
					max = arr[i];
				}
			}
			cout<<"\nMAX:"<<max;
		}
		void average() {
			int sum=0;
			for(int i=0;i<n;i++) {
				sum += arr[i];
			}
			cout<<"\nAVERAGE:"<< (float) sum /n;
		}
		void sort() {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(arr[i] < arr[j]) {
						int temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			
			cout<<"\nSORTED ARRAY";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
		}
};

int main() {
	Array arr;
	arr.inputArray();
	arr.display();
	arr.largest();
	arr.average();
	arr.sort();
	cout<<endl;

}

#include<iostream>
using namespace std;

class Opr {
	int arr[10];
	int n;
	public:
		void insert() {
			cout<<"Enter n:";
			cin>>n;
			cout<<"Enter array ele:";
			for(int i=0;i<n;i++) 
				cin>>arr[i];
		}
			
		void display() {
			cout<<"\nArray Elements:";
			for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
		}
		void operator -- () {
			for(int i=0;i<n;i++) 
				arr[i] = arr[i] - 1;
		}
		void operator ++ (int) {
			for(int i=0;i<n;i++) 
				arr[i] = arr[i] + 1;
		}
		friend Opr operator + (Opr o1, Opr o2) {
			Opr o3;
				
			cout<<"\nFUNC Array: +";
			for(int i=0;i<o1.n;i++)
				cout<<o1.arr[i]<< " ";
	
			for(int i=0;i<o1.n;i++) 
				o3.arr[i] = o1.arr[i] + o2.arr[i];

			o3.n =o1.n;
			return o3;	
		}
		friend Opr operator * (Opr o1 ,int x) {
			Opr o4;
			cout<<"\nFUNC Array:i *";
			for(int i=0;i<o1.n;i++)
				cout<<o1.arr[i]<< " ";

			for(int i=0;i<o1.n;i++) 
				o4.arr[i] = o1.arr[i] * x;
	
			o4.n = o1.n;
			return o4;
		}

};

int main() {
	int x = 10;
	Opr o1;
	Opr o2;
	
	o1.insert();	
	//--o1;
	//o1.display();
	//o1++;
	//o1.display();

	o2.insert();
	//Opr o3 = o1 + o2;
	//o3.display();	
	Opr o4 = o1 + o2 * x;
	o4.display();
	cout<<endl;

}

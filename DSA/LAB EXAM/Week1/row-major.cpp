#include<iostream>
using namespace std;


int main() {
    int arr[10][10],newArr[10],n;
    cout<<"Enter the value of n:";
    cin>>n;

    cout<<"Enter Array Elements:";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
                cin>>arr[i][j]; 
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            newArr[count++] = arr[i][j];
        }
    }
    cout << endl;
    cout<<"1 Array:";
    
    for(int i=0;i<count;i++) { 
        cout<<newArr[i]<<" ";
    }
    cout<<endl; 
}
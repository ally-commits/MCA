#include<iostream>
using namespace std;


int main() {
    int arr[20],n;
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter Array Elements:";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int key;
    for(int i=1;i<n;i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] =  key;
    }


    cout<<"Array Elements:";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
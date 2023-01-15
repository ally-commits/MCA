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

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1;j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }


    cout<<"Array Elements:";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
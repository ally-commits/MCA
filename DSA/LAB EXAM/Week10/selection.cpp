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
        int minIndex = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }


    cout<<"Array Elements:";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
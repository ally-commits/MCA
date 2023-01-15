#include<iostream>

using namespace std;


void merge(int arr[],int low,int high,int mid) {
    int i,j,k,c[10];
    i = low;
    k = low;
    j = mid + 1;

    while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        } else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while(j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }

    for(i=low;i<k;i++)
        arr[i] = c[i];
}

void mergeSort(int arr[],int low,int high) {
    int mid;
    if(low < high) {
        mid = (low+high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, high, mid);
    }
}

int main() {
        int arr[10],n;
        cout<<"Enter Number of elements:";
        cin>>n;
        cout<<"Enter Array Elements:";
        for(int i=0;i<n;i++) {
                cin>>arr[i];
        }
        mergeSort(arr,0,n-1);

        cout<<"Sorted Array:\n";
        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";

        cout<<endl;

}

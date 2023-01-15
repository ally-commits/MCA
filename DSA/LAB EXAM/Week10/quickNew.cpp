#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i= low + 1;
    int j = high;

    while(i < j && arr[i] < pivot)
        i++;
    
    while(arr[j] > pivot)
        j--;

    if(i < j) 
        swap(arr[i],arr[j]);
    else
        swap(arr[low], arr[j]);

    return j;
}

void quickSort(int arr[],int low,int high) {
    if(low < high) {
        int j = partition(arr,low,high);
        quickSort(arr,low,j);
        quickSort(arr, j+1, high);
    }
}

int main () {
    int n, arr[10];

    cout << "Enter size: ";
    cin >> n;

    cout << "Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "SORTED: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}
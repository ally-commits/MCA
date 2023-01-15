#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    } 
    return -1;
}

int main() {
    int arr[30], n,ele;
    cout << "Enter value of n:";
    cin >> n;

    cout << "Enter Array elements:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"Enter Search Element:";
    cin>>ele;

    int result = binarySearch(arr, 0, n-1, ele);
    if (result == -1)
        cout << "Element not Found:";
    else
        cout << "Element Found at index " << result;

    cout<<"\n";
    return 0;
}
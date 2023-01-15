#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
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
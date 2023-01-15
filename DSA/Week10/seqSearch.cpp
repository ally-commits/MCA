#include <iostream>
using namespace std;

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
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

    int result = search(arr, n, ele);
    if (result == -1)
        cout << "Element not Found:";
    else
        cout << "Element Found at index " << result;

    cout<<"\n";
    return 0;
}
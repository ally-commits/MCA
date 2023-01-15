#include <iostream>
using namespace std;

int main() {
    int n;
    system("clear");

    cout << "Enter decimal number:";
    cin >> n;

    cout<<"Bainary Number:";
    int arr[20], i = 0;
    for (i = 0; n > 0; i++) {
        arr[i] = n % 2;
        n = n / 2;
    } 
    for (int j = i - 1; j >= 0; j--)
        cout << arr[j];

    cout<<"\nEnter Bainary number:";
    cin>>n;

    int dec = 0, rem, base = 1;
    while (n) {
        rem = n % 10;
        n /= 10;
        dec += rem * base;
        base *= 2;
    }
    cout<<"Decimanl Number:"<<dec;

    cout << endl;
}

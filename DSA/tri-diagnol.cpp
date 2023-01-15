#include<iostream>
using namespace std;
 
int main() {
    int n,m,arr[10][10],newArr[10];

    cout<<"Enter n and m value:";
    cin>>n>>m;

    cout<<"Enter Array elements\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i == j || i == j+1 || i == j-1) {
                cin>>arr[i][j];
            } else {
                arr[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i == j || i == j+1 || i == j-1)
                newArr[count++] = arr[i][j];
        }
    }

    cout<<"\nArray 1d elements:";
    for(int i=0;i<count;i++)
        cout<<newArr[i]<<" ";

    cout<<"\nEnter index:";
    int row,col;
    cin>>row>>col;
    int index = 2 * row + col;

    cout<<"\nElement:"<<arr[row][col]<<" found at location "<<index<<endl;
}
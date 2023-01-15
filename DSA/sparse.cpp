#include<iostream>
using namespace std;


struct sparse{
    int row,col,value;
};


void display(int arr[][10], int n,int m) {
    cout<<"\n\nMatrix Displaying...\n";

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}
int main() {
    sparse sp[10];
    int arr[10][10],newArr[10][10];
    int n,m;
    cout<<"enter value of n:";
    cin>>n>>m;

    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    display(arr,n,m);
    
    sp[0].row = n;
    sp[0].col = m;
    sp[0].value = 0;
    int count = 1; 

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] != 0) {
                sp[count].row = i;
                sp[count].col = j;
                sp[count].value = arr[i][j];
                count++;
            }
        }
    }
    cout<<"\n";
    for(int i=0;i<count;i++) {
        cout<<sp[i].row<<" "<<sp[i].col<<" "<<sp[i].value<<endl;
    }
    count = 1;
    for(int i=0;i<sp[0].row;i++) {
        for(int j=0;j<sp[0].col;j++) {
            if (i == sp[count].row && j == sp[count].col) {
                newArr[i][j] = sp[count].value;
                count++;
            } else {
                newArr[i][j] = 0;
            }
        }
    }

    display(newArr,sp[0].row, sp[0].col);
}
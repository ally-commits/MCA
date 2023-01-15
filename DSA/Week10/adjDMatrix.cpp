#include<iostream>
using namespace std;


void addVertex(int arr[][10]) {
    cout<<"\n Enter Starting vertex and ending vertex:";

}   


int main() {
    int arr[10][10],n,choice;

    cout<<"Enter the size of vertex:";
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j] = 0;

    do {
        cout<<"\n1.Add Edge\n2.Display\n3.Exit";
        cin>>choice;

    } while(choice != 3);
}
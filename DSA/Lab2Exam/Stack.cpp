#include<iostream>
using namespace std;

void push(int arr[],int &top,int size) {
    if(top == size) 
        cout<<"Stack is Full";
    else {
        int element ;
        cout<<"Enter element:";
        cin>>element;
        arr[top++] = element;
    }  
}
void pop(int arr[],int &top) {
    if(top == 0)
        cout<<"Stack is empty";
    else {
        cout<<"Element:"<<arr[--top]<<":deleted";
    }
}

int main() {
    system("clear");
    int n,top=0;
    cout<<"Enter size of array:";
    cin>>n;

    int arr[n];
    int choice;
    do{
        cout<<"\n1.Push\n2.Pop\n3.Exit";
        cin>>choice;

        if(choice == 1) {
            push(arr,top,n);
        } else if(choice == 2) {
            pop(arr,top);
        } 
    } while(choice != 3);
}
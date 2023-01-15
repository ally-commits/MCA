#include<iostream>
using namespace std;

void enQueue(int arr[], int &rear,int size) {
    if(rear == size) {
        cout<<"Queue is full";
    } else {
        int element;
        cout<<"Enter element:";
        cin>>element;
        arr[rear++] = element;
    }
}

void deQueue(int arr[],int &rear,int &front) {
    if(rear == front) {
        cout << "Queue is empty";
    } else {
        cout<<arr[front++]<< "got deleted";
    }
}
void display(int arr[],int rear) {
    for(int i=0;i<rear;i++) {
        cout<<arr[i]<< " ";
    }
}
int main() {
    int arr[10],front=0,rear=0,size=5;

    enQueue(arr,rear,size);
    display(arr,rear);
    enQueue(arr, rear, size);
    display(arr, rear);
    enQueue(arr, rear, size);
    display(arr, rear);
    enQueue(arr, rear, size);
    display(arr, rear);

    enQueue(arr, rear, size);
    display(arr, rear);

    deQueue(arr,rear,front);
     
    display(arr, rear);
    deQueue(arr, rear, front);
    display(arr, rear);

    deQueue(arr, rear, front);
    display(arr, rear);
}
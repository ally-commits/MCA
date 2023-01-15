#include<iostream>
using namespace std;
void enQueue(int queue[],int &rear,int size) {
    if(rear == size) {
        cout<<"Queue is full";
    } else {
        cout<<"Enter element:";
        cin>>queue[rear++];
    }
}

void deQueue(int queue[],int rear,int &front) {
    if(rear == front) { 
        cout<<"Queue is empty";
    } else {
        cout<<"Element:"<<queue[front++]<<"deleted";
    }
}
void display(int queue[],int &rear,int &front) {
    cout<<"\n\n";
    for(int i=front;i<rear;i++) {
        cout<<queue[i]<<" ";
    }
}
int main() {
    int n,rear=0,front=0;
    cout<<"Enter the value of n:";
    cin>>n;

    int queue[n];
    int choice;
    do {
        cout<<"\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit";
        cin>>choice;

        if(choice == 1) 
            enQueue(queue,rear,n);
        else if(choice == 2)
            deQueue(queue,rear,front);
        else if(choice == 3) 
            display(queue,rear,front);
    } while(choice != 4);
}
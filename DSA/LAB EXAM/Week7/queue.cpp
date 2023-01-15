#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void enQueue(node *rear,node *front) {
    struct node *newNode = new struct node;
    struct node *tempNode = rear;
    
    int ele;
    cout<<"Enter element:";
    cin>>ele;
    
    newNode->data = ele;
    newNode->next = NULL;

    if(rear->next == NULL) {
        rear->next = newNode;
        front->next = newNode;
    } else {
        while(tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
        rear->next = newNode;
    }
}

void deQueue(node *rear,node *front) {
    struct node *tempNode = front->next;
    if(front->next == NULL) {
        cout<<"Queue is empty";
    } else {
        front->next = tempNode->next;
        cout<<tempNode->data;
    }
}

void displayNode(node *front) {
        struct node *tempNode = front;
        cout<<"\nList Elements:";
        while(tempNode->next != NULL) {
                tempNode = tempNode->next;
                cout<<tempNode->data;
                if(tempNode->next != NULL)
                        cout<<"->";
        }
}
int main() {
        struct node *rear;
        rear = (node*)  malloc (sizeof(node));
        rear->next = NULL;

        struct node *front;
        front = (node*) malloc (sizeof(node));
        front->next = NULL;


        int choice;
        do {
                cout<<"\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\nEnter Choice:";
                cin>>choice;
                if(choice == 1)
                        enQueue(rear, front);
                else if(choice == 2)
                        deQueue(rear, front);
                else if(choice == 3)
                        displayNode(front);

        } while(choice != 4);
        cout<<endl;
}

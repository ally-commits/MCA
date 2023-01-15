#include<iostream>
using namespace std;


struct node {
    int data;
    struct node *next;
};

void push(node *head) {
    struct node *tempNode = head;
    struct node *newNode = new struct node;
    int element;
    cout<<"Enter element:";
    cin>>element;
    newNode->data = element;
    if(head->next == NULL) {
        head->next = newNode;
        newNode->next = NULL;
    }  else {
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void pop(node *head) {
    struct node *tempNode = head;

    if(tempNode->next == NULL) {
        cout<<"Stack is empty";
    } else {
        cout<<"Element got deleted:"<<tempNode->next->data;
        tempNode->next = tempNode->next->next;
    }
}
void display(node *top) {
        struct node *tempNode = top;
        cout<<"\nList Elements:";
        while(tempNode->next != NULL) {
                tempNode = tempNode->next;
                cout<<tempNode->data;
                if(tempNode->next != NULL)
                        cout<<"->";
        }
}
int main() {
    struct node *top;
    top = (node *)malloc(sizeof(node));
    top->next = NULL;

    int choice;
    do
    {
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Choice:";
        cin >> choice;
        if (choice == 1)
            push(top);
        else if (choice == 2)
            pop(top);
        else if (choice == 3)
            display(top);

    } while (choice != 4);
    cout << endl;
    return 1;
}
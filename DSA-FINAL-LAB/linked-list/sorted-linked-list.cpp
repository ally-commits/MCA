#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void insertNode(node *head) {
    struct node *newNode = new struct node;
    int element;
    cout<<"Enter Element:";
    cin>>element;

    newNode->data = element;

    if(head->next == NULL) {
        head->next = newNode;
        newNode->next = NULL;
    } else {
        struct node *tempNode=head;
        while (tempNode->next != NULL && tempNode->next->data < element) {
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void deleteNode(node *head) {
    struct node *tempNode = head;
    struct node *prevNode = head;

    if(tempNode->next == NULL) {
        cout<<"List is empty";
    } else {
        int element,found=0;
        cout << "Enter deleting element:";
        cin >> element;

        while (tempNode->next != NULL && element < tempNode->data) {
            tempNode = tempNode->next;
            prevNode = tempNode;
            if(tempNode->data == element) {
                found = 1;
            }
        }
        if(found)
            prevNode->next = tempNode->next;
        else    
            cout<<"Element not found";
    }


}
void displayNode(node *head) {
    struct node *tempNode = new struct node;
    tempNode = head->next;

    while(tempNode->next != NULL) {
        cout<<tempNode->data<<"-";
        tempNode = tempNode->next;
    }
    cout<<tempNode->data;
}

int main() {
    struct node *head = new struct node;
    head->next = NULL;

    int choice;
    do {
        cout << "\n1.Insert Element\n2.Delete Element\n3.Display\n4.Exit\nEnter Choice:";
        cin >> choice;
        if (choice == 1)
            insertNode(head);
        else if (choice == 2)
            // deleteNode(head);
            cout<<"DELETE";
        else if (choice == 3)
            displayNode(head);

    } while (choice != 4);
}
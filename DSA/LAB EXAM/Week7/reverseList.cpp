#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};


void insertNode(node *head) {
    struct node *tempNode = head;
    struct node *newNode = new struct node;

    int element;
    cout << "Enter element:";
    cin >> element;
    newNode->data = element;
    if(head->next == NULL) {
        head->next = newNode;
        newNode->next = NULL;
    } else {
        while(tempNode->next != NULL && tempNode->next->data < element) {
            tempNode = tempNode-> next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void deleteNode(node *head) {
    struct node *tempNode = head;
    struct node *prevNode = tempNode;

    int element;
    cout << "Enter element:";
    cin >> element;
    if(head->next == NULL) {
        cout<<"Empty";
    } else {
        int found = 0;
        while(tempNode->next != NULL && tempNode->data < element) {
            prevNode = tempNode;
            tempNode = tempNode->next;

            if(tempNode->data == element) {
                found = 1;
            }
        }

        if(found == 1) {
            prevNode->next = tempNode->next;
            cout<<tempNode->data<<"deleted";
        } else {
            cout<<"Element not found";
        }
    }       
}

void displayNode(node *head) {
    cout<<endl;

    struct node *tempNode = head;
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
        cout << tempNode->data << " ";
    }

    cout<<endl;
}

void reverseNode(node *head) {
    if(head->next != NULL) {
        reverseNode(head->next);
    }
    cout<<head->data<<" ";
}

int main() {
    struct node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;

    int choice;
    do
    {
        cout << "\n1.Insert Element\n2.Delete Element\n3.Display\n4.Exit\nEnter Choice:";
        cin >> choice;
        if (choice == 1)
            insertNode(head);
        else if (choice == 2)
            deleteNode(head);
        else if (choice == 3)
            displayNode(head);
        else if (choice == 4)
            reverseNode(head);

    } while (choice != 4);
    cout << endl;
}

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insert() {
    struct node *newNode = new struct node;

    int element;
    cout<<"Enter element:";
    cin>>element;

    struct node *tempNode = head;
    struct node *prevNode = tempNode;

    
}
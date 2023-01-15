#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
void insertNode(node *root) {
    int element;
    cout<<"Enter Element:";
    cin>>element;

    struct node *newNode = new struct node;
    newNode->data = element;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    struct node *parentNode = root;
    struct node *tempNode = root->leftChild;

    if(root->leftChild == NULL) {
        root->leftChild = newNode;
    } else {
        do {
            parentNode = tempNode;
            if(element < tempNode->data) {
                tempNode = tempNode->leftChild;
            } else{
                tempNode = tempNode->rightChild;
            }
        } while(tempNode != NULL);

        if(element < parentNode->data) {
            parentNode->leftChild = newNode;
        } else {
            parentNode->rightChild = newNode;
        }
    }
}


void inOrder(node *root) {
        if(root != NULL) {
                inOrder(root->leftChild);
                cout<<root->data<<" ";
                inOrder(root->rightChild);
        }
}
void preOrder(node *root) {
        if(root != NULL) {
                cout<<root->data<<" ";
                preOrder(root->leftChild);
                preOrder(root->rightChild);
        }
}
void postOrder(node * root) {
    if(root != NULL) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->data<<" ";
    }
}

int main() {
        struct node *root;
        root = (node*)  malloc (sizeof(node));
        root->leftChild = NULL;

        int choice;
        do {
                cout<<"\n1.Insert Element\n2.PreOrder\n3.InOrder\n4.PostOrder\n5.Exit\nEnter Choice:";
                cin>>choice;
                if(choice == 1) {
                        insertNode(root);
                } else if(choice == 2) {
                        cout<<"\nPreOrder BST:";
                        preOrder(root->leftChild);
                } else if(choice == 3) {
                        cout<<"\nInOrder BST:";
                        inOrder(root->leftChild);
                } else if(choice == 4) {
                        cout<<"\nPostOrder BST:";
                        postOrder(root->leftChild);
                }

        } while(choice != 4);
        cout<<endl;
}
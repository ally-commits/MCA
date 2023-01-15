#include<iostream>
using namespace std;

struct Node {
        int val;
        Node* next;
};
struct Edge {
        int src,dest;
};
class Graph {
        Node* getAdjListNode(int dest,Node* head) {
                Node* newNode = new Node;
                newNode->val = dest;
                newNode->next = head;

                return newNode;
        }
        int n;
        public:
                Node **head;
                Graph(Edge edges[],int n) {
                    head = new Node*[n]();
                    this->n = n;
                    for(int i=0;i<n;i++) {
                        head[i] = nullptr;
                    }
                    for(int i=0;i<n;i++) {
                        int src = edges[i].src;
                        int dest = edges[i].dest;

                        Node* newNode = getAdjListNode(dest, head[src]);
                        head[src] = newNode;
                    }
                }
                ~Graph() {
                    for(int i=0;i<n;i++) {
                            delete[] head[i];
                    }
                    delete[] head;
                }
};

void printList(Node* ptr) {
        while(ptr != nullptr) {
            cout<<"->"<<ptr->val;
            ptr = ptr->next;
        }
        cout<<endl;
}

int main() {
        int n;
        Edge edges[10];
        cout<<"Enter number of edges:";
        cin>>n;
        cout<<"Enter edges:";
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            edges[i].src = a;
            edges[i].dest = b;
        }

        Graph graph(edges, n);
        cout<<"Graph list:\n";
        for(int i=0;i<n;i++) {
                if(graph.head[i] != nullptr) {
                    cout<<i;
                    printList(graph.head[i]);
                }
        }
        return 0;
}

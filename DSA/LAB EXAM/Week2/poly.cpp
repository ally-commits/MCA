#include<iostream>
using namespace std;

struct poly {
    int col,exp;
};
int main() {
    poly p1[10],p2[10],p3[10];
    int n1,n2;

    cout<<"Enter the n1:";
    cin>>n1;
    cout<<"Enter poly";
    for(int i=1;i<=n1;i++) {
        cin>>p1[i].col;
        cin>>p1[i].exp;
    }
    p1[0].col = n1;

    cout<<"Enter the n2:";
    cin>>n2;
    cout << "Enter poly";
    for(int i=1;i<=n2;i++) {
        cin>>p2[i].col;
        cin>>p2[i].exp;
    }
    p2[0].col = n2;

    int k=1,i=1,j=1;
 
    while(i <= n1 && j <= n2) {
        if(p1[i].exp == p2[j].exp) {
            p3[k].col = p1[i].col + p2[j].col;
            p3[k].exp = p1[i].exp;
            k++;
            i++;
            j++;
        } else if(p1[i].col > p2[j].col) {
            p3[k].col = p1[i].col;
            p3[k].exp = p1[i].exp;
            k++;
            i++; 
        } else {
            p3[k].col = p2[j].col;
            p3[k].exp = p2[j].exp;
            k++;
            j++;
        }
    }
    while(i <= n1) {
        p3[k].col = p1[i].col;
        p3[k].exp = p1[i].exp;
        k++;
        i++;
    }
    while(j <= n2) {
        p3[k].col = p2[j].col;
        p3[k].exp = p2[j].exp;
        k++;
        j++;
    }

    p3[0].col = k;

    cout<<"Addition of 2 poly:\n";

    for(int i=1;i<p3[0].col;i++) {
            cout<<p3[i].col;

            // if(p3[i].exp != 0)
            cout<<"x^"<<p3[i].exp;

            if(i < k - 1)
                cout<<" + ";
            else
                cout<<"    ";
    }

    cout<<endl;
    return 1;
}
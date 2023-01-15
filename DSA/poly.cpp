#include<iostream>
using namespace std;


struct poly {
    int exp,col;
};

int main() { 
    poly poly1[10],poly2[10],poly3[20];

    cout<<"Enter Poly 1 Len:";
    cin>>poly1[0].col;

    for(int i=1;i<=poly1[0].col;i++) {
        cin>>poly1[i].exp;
        cin>>poly1[i].col;
    }


    cout<<"Enter Poly 2 Len:";
    cin>>poly2[0].col;

    for(int i=1;i<=poly2[0].col;i++) {
        cin>>poly2[i].exp;
        cin>>poly2[i].col;
    }
    int count=1,i=1,j=1;
    for(int k=1;k<= poly1[0].col + poly2[0].col; k++) {
        if(i > poly1[0].col) {
            poly3[count].col = poly2[j].col;
            poly3[count].exp = poly2[j].exp;
            count++;
            j++;
            continue;
        }
        if(j > poly2[0].col) {
            poly3[count].col = poly1[i].col;
            poly3[count].exp = poly1[i].exp;
            count++;
            i++;
            continue;
        }
        if(poly1[i].exp < poly2[j].exp) {
            poly3[count].col = poly2[j].col;
            poly3[count].exp = poly2[j].exp;
            count++;
            j++;
        } else if(poly1[i].exp > poly2[j].exp) {
            poly3[count].col = poly1[i].col;
            poly3[count].exp = poly1[i].exp;
            count++;
            i++;
        } else {
            poly3[count].col = poly1[i].col + poly2[j].col;
            poly3[count].exp = poly1[i].exp;
            count++;
            i++;
            k++;
            j++;
        }
    }
    poly3[0].col = count;


     cout<<"Addition of 2 poly:\n";

    for(int i=1;i<poly3[0].col;i++) {
        if(poly3[i].col == 0)
            continue;
            
        cout<<poly3[i].col;

        if(poly3[i].exp != 0)
                cout<<"x^"<<poly3[i].exp;

        if(i < count - 1)
                cout<<" + ";
    }

}
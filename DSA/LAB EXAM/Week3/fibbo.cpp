#include<iostream>
using namespace std;


int fibbo(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else 
        return fibbo(n-1) + fibbo(n-2);
}

int main() {
    for(int i=0;i<10;i++) {
        cout<<fibbo(i)<< " ";
    }
    cout<<endl;
}
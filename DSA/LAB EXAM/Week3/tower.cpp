#include<iostream>
using namespace std;

void tower(int n,char a,char b,char c) {
    if(n == 1) {
        cout<<endl<<a<<"->"<<b;
    } else {
        tower(n-1,a,c,b);
        cout<<endl<<a<<"->"<<b;
        tower(n-1,c,b,a);
    }
}

int main() {
    tower(3,'A','B','C');
}
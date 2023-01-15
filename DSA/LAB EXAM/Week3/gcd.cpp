#include<iostream>
using namespace std;

int gcd(int a,int b) {
    if(a == 0) 
        return b;
    else if(b == 0)
        return a;
    else    
        return gcd(b ,a %b);
}

int main() {
    cout<<gcd(10,20)<<endl;
}

#include<iostream>
using namespace std;

int main() {
        int f1,f2,n;
        system("clear");
        cout<<"Enter value of n:";
        cin>>n;

        f1=0;
        f2=1;
        if(n >= 1)
                cout<<f1<<" ";
        if(n >= 2)
                cout<<f2<<" ";
        for(int i=2;i<n;i++) {
                int val = f1 + f2;
                f1 = f2;
                f2 = val;
                cout<<f2<<" ";
        }
        cout<<endl;

}

#include <iostream>
using namespace std;


int main() {
        int lower,upper;
        system("clear");
        cout<<"Enter lower and upper bound:";
        cin>>lower>>upper;
        int count = 0;
        cout<<"Prime numbers:";
        for(int i=lower;i<=upper;i++) {
                int divided = 0;
                for(int j=2;j<i;j++) {
                        if(i % j == 0) {
                                divided = 1;
                        }
                }
                if(divided == 0){
                        count = 1;
                        cout<<i<<" ";
                }
        }
        if(count == 0)
                cout<<"None";
        cout<<endl;
}
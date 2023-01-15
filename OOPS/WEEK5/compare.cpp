//Name: Alwin Crasta
//Regno: 210970125
//Date: 07-01-2022
//Program Name:Write a C++ program to overload the relational operators <= to compare 2 objects of my_String class

#include<iostream>
using namespace std;

class MyString {
    char str[20];
    public:
            MyString() {
                    cout<<"Enter String value:";
                    cin>>str;
            }
            int operator <= (MyString str2) {
		int i=0;
		while(str[i] != '\0' || str2.str[i] != '\0') {
			if(str[i] == str2.str[i]) {
				i++;
				continue;	
			}
			if(str[i] < str2.str[i]) 
				return 1;
			else
				return 0;
				
		}	
		return 1;
            }
};
int main() {
    system("clear");

    MyString str1;
    MyString str2;

    if(str1 <= str2) {
            cout<<"\nString 1 is less than or equal to String 2";
    } else {
            cout<<"\nString 1 is greator than String 2";
    }
    cout<<endl;

    return 0;
}

#include<iostream>
#include<string.h>

using namespace std;


int main() {
	string str;
	int k;
		
	cout<<"Enter string value:";
	getline(cin,str);
	
	cout<<"Enter value for k:";
	cin>>k;

	for(int i=0;i<str.length();i++) {
		if(str[i] == 32) {
			cout<<" ";
		} else {
			char ch = str[i] + k;
			cout<<ch;
		}
	}
	cout<<endl;
}

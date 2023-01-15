#include<iostream>
using namespace std;

class Str {
	char str[100];
	public:
		//iStr() {
		//	cout<<"\nEnter String:";
		//	cin>>str;
		//}
		void insert() {
			cout<<"Enter String:";
			cin>>str;
		}
		Str copy(char* s){
			Str s1;
			int i=0;
			for(i=0;s[i] != '\0';i++) 	
				s1.str[i] = s[i];

			s1.str[i] = '\0';
			return s1;
			
		}
		void display() {
			cout<<"\nString:"<<str<<"END";
		}

};
int main() {
	Str s;	
	s.insert();
	char str[100];
	cout<<"Enter copy string:";
	cin>>str;
	Str s2 = s.copy(str);
	s.display();
	s2.display();
	
}

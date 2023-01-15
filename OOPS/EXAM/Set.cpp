#include<iostream>
using namespace std;

class Set {
	char s[100];
	int n;
	public:
		void insert() {
			cout<<"Enter String:";
			cin>>s;
			length();
		}
		void length() {
			int i;
			for(i=0;s[i] != '\0';i++);
			n = i;	
		}
		void unionFunc(Set s2) {
			char str[20];
			int k = 0;
			for(int i=0;i<n;i++) {
				int found = 0;
				for(int j=0;j<k;j++) 
					if(str[j] == s[i])
						found = 1;
				
				if(found == 0) 
					str[k++] = s[i];
			}
			for(int i=0;i<s2.n;i++) {
				int found = 0;
				for(int j=0;j<k;j++)
					if(str[j] == s2.s[i])
						found = 1;
				
				if(found == 0) 
					str[k++] = s2.s[i];
			}
			str[k] = '\0';
			cout<<"\nUNION:"<<str;
		}
		void intersectionFunc(Set s2) {
			char str[100];
			int k=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<s2.n;j++) {
					if(s[i] == s2.s[j]) {
						str[k++] = s[i];
					}
				}
			}
			str[k] = '\0';
			cout<<"\nINTERSECTION:"<<str;
		}
		void diffrenceFunc(Set s2) {
			char str[100];
			int k=0;
				
			for(int i=0;i<n;i++) {
				int found = 0;
				for(int j=0;j<s2.n;j++) {
					if(s[i] == s2.s[j]) {
						found = 1;
					}
				}
				if(found == 0){
					str[k++] = s[i];
				}
			}
			str[k] = '\0';
			cout<<"\nDIFFRENCE:"<<str;

		}
};
int main() {
	Set s1;
	Set s2;
		
	s1.insert();
	s2.insert();
	
	s1.unionFunc(s2);
	s1.intersectionFunc(s2);
	s1.diffrenceFunc(s2);
	
	cout<<endl;
}

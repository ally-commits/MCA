//Name: Alwin Crasta
//Regno: 210970125
//Date: 07-01-2022
//Program Name: Design the classes using following hierarchical inheritance teaching. Each class has member functions accept and display.


#include<iostream>
using namespace std;

class Person {
	int id;
	char name[20];
		
	public:
		void accept() {
			cout<<"Enter Id:";
			cin>>id;
			cout<<"Enter Name:";
			cin>>name;
		}
		void display() {
			cout<<"\nId:"<<id;
			cout<<"\nName:"<<name;
		}
};

class Teaching:public Person {
	char subject[20];
	char name[20];
		
	public:	
		void accept() {
			cout<<"Enter Subject Name:";
			cin>>subject;
			cout<<"Enter Name:";
			cin>>name;
		}
		void display() {
			cout<<"\nSubject:"<<subject;
			cout<<"\nName:"<<name;
		}
};

class NonTeaching:public Person {
	char dept[10];
	
	public:
		void accept() {
			cout<<"Enter Department:";
			cin>>dept;
		}
		void display() {
			cout<<"\nDepartment:"<<dept;
		}


};

class Instructor:public Person {
	char course[20];
	public:
		void accept() {
			Person::accept();
			cout<<"Enter Cource Name:";
			cin>>course;
		}
		
		void display() {
			Person::display();
			cout<<"\nCourse:"<<course;
		}
};

int main() {
	Instructor obj[10];
	int n;
	system("clear");
	cout<<"Enter number of instructors:";
	cin>>n;

	for(int i=0;i<n;i++) {
		obj[i].accept();
	}		

	for(int i=0;i<n;i++) {
		cout<<"\n------------------------";
		obj[i].display();
	}
} 

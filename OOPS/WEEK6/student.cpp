//Name:Alwin Crasta
//RegNo: 210970125
//Date: 13-JAN-2022
//Pr
#include<iostream>
using namespace std;

class Student {
	public:
		char name[10];
		int id;

		void insertDetails() {
			cout<<"Enter id & name:";
			cin>>id>>name;
		}	
};

class Marks:public virtual Student {
	public:
		int marks[5];

		void insertMarks() {
			cout<<"Enter marks in 5 subjects:";
			for(int i=0;i<5;i++) {
				cin>>marks[i];
			}
		}
};

class Sports:public virtual Student {
	public:
		int sportsMarks;

		void insertSportsMark() {
			cout<<"Enter Sports Marks:";
			cin>>sportsMarks;
		}
};

class Result:public Sports,public Marks {
	int total = 0;
	public:
		void calculateMarks() {
			for(int i=0;i<5;i++) {
				total+=marks[i];
			}
			total += sportsMarks;
		}
		void display() {	
			cout<<"\nId:"<<id;
			cout<<"\nName:"<<name;
			cout<<"\nMarks:";
			for(int i=0;i<5;i++) {
				cout<<marks[i]<<" ";
			}
			cout<<"\nSports Marks:"<<sportsMarks;
			cout<<"\nTotal Marks:"<<total;
			cout<<"\nPercentage:"<<total/6;
		}	
};
int main() {
	system("clear");
	Result r;
	r.insertDetails();
	r.insertMarks();
	r.insertSportsMark();
	r.calculateMarks();
	r.display();
	cout<<endl;
}

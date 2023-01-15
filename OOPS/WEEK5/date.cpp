//Name: Alwin Crasta
//Regno: 210970125
//Date: 07-01-2022
//Program Name: Write a C++ program to create a class called Date, which contains integer members to represent day, month, and year. The overload ++ operator to increment the value of Date object by one.  

#include<iostream>
using namespace std;

class Date {
	int day, month,year;
	public:
		Date() {
			day = 29;
			month = 1;
			year = 2022;
		}

		void operator ++ (int) {
			cout<<"\nDate Increment";
			if(month == 12 && day == 31) {
				day = 1;
				month=1;
				year++;
			} else if(day == 31) {
				month++;
				day=1;
			} else {
				day++;
			}
		}
		void display() {
			cout<<"\nDate:"<<day<<"-"<<month<<"-"<<year;

		}
};

int main() {
	Date d1;
	system("clear");
	
	d1++;
	d1.display();
	d1++;
	d1.display();
	d1++;
	d1.display();
	
	cout<<endl;	
}

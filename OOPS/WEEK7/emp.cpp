#include<iostream>
using namespace std;

class Employee {
	public:
        char name[10];
        virtual void accept() {
			
		}	
		virtual void display() {
			
		}		
};

class Education {
	public:
        char education[20];

        virtual void accept() {
			
		}
		virtual void display() {
			
		}	
};

class Laborer:public Employee {
	int workHours;
	public:
		void accept() {
            cout << "Enter Name:";
            cin >> name; 
            cout<<"Enter Works Hours:";
			cin>>workHours;
		}
		void display() {
            cout <<"\nName:" << name;
            cout<<"\nWork Hours:"<<workHours;
		}
};

class Scientist: public Employee,public Education {
	char expertise[10];
	public:
		void accept() {
            cout << "Enter Name:";
            cin >> name; 
            cout << "Enter Education:";
            cin >> education;
            cout<<"Enter Expertise:";
			cin>>expertise;
		}
		void display() {
            cout << "\nName:" << name;
            cout << "\nEducation:" << education;
            cout<<"\nExpertise:"<<expertise;
		}
};

class Manager: public Employee,public Education {
	char dept[10];
	public:
		void accept() {
            cout << "Enter Name:";
            cin >> name; 
            cout << "Enter Education: ";
            cin >> education;
            cout<<"Enter Department:";
			cin>>dept;
		}
		void display() {
            cout << "\nName:" << name; 
            cout << "\nEducation:" << education;
            cout<<"\nDepartment:"<<dept;
		}
};

int main() {
	Employee *emp;
    Scientist s;
    emp = &s;
    cout << "\n---Scientist\n";
    emp->accept();
    emp->display();

    Laborer l;
    emp = &l;
    cout << "\n---Laborer\n";
    emp->accept();
    emp->display();

    Manager m;
    emp = &m;
    cout << "\n---Manager\n";
    emp->accept();
    emp->display();
}

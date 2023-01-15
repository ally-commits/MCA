#include<iostream>
using namespace std;

class Complex {
        int real,img;

        public:
                void insert() {
                        cout<<"\nEnter real value:";
                        cin>>real;
                        cout<<"Enter img value:";
                        cin>>img;
                }

                friend Complex add(int, Complex);

                friend Complex add(Complex,Complex);

                void display() {
                        cout<<"\nReal number:"<<real;
                        cout<<"\nImg number:"<<img;
                }

};

Complex add(int s1,Complex s2) {
        Complex c1;
        c1.img = s2.img + s1;
        c1.real = s2.real + s1;

        return c1;
}

Complex add(Complex s1,Complex s2) {
        Complex c1;
        c1.real = s1.real + s2.real;
        c1.img = s1.img + s2.img;

        return c1;
}

int main() {
        Complex c1;
        Complex c2;
        Complex c3,c4;

        system("clear");

        c1.insert();
        c2.insert();

        int value;
        cout<<"\nEnter integer value:";
        cin>>value;

        c3 = add(value,c1);
        c4 = add(c1,c2);

        cout<<"\nAdd s1 integer,s2 object";
        c3.display();

        cout<<"\n\nAdd s1 object,s2,object";
        c4.display();

        cout<<endl;
        return 0;
}
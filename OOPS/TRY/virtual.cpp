// CPP program to illustrate
// concept of Virtual Functions

#include <iostream>
using namespace std;

class base
{
public:
    void print()
    {
        cout << "print base class" << endl;
    }

    void show()
    {
        cout << "show base class" << endl;
    }
};

class derived : public base
{
public:
    void print()
    {
        cout << "print derived class" << endl;
    }

    void show()
    {
        cout << "show derived class" << endl;
    }
};

int main()
{
    base *bptr[10];
    derived d;
    bptr[0] = &d;

    // // // virtual function, binded at  runtime
    bptr[0]->print();
    // bptr.base::print();

    // // Non-virtual function, binded at compile time
    // bptr->show();

    // derived b;
    // b.print();
}

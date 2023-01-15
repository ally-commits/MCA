
#include <iostream>
using namespace std;

class Bank
{
    int accountNumber;
    char name[20], accountType;
    static int inc;

public:
    int balance;

    Bank()
    {
        balance = 500;
        cout << "\nEnter Name:";
        cin >> name;
        cout << "Account Type(Saving (S), Fixed(F), Current(C):";
        cin >> accountType;
        accountNumber = ++inc;
    }
    void depositAmount()
    {
        int value;
        cout << "Enter the deposit amount:";
        cin >> value;

        balance += value;
    }

    void displayInfo()
    {
        cout << "\n-------------------------";
        cout << "\nAccount Number:" << accountNumber;
        cout << "\nName:" << name;
        cout << "\nAccount Type:" << accountType;
        cout << "\nBalance:" << balance << ".Rs\n";
    }

    friend void withdraw(Bank &);
};

int Bank::inc;

void withdraw(Bank &b)
{
    int value;
    cout << "Enter withdraw amount:";
    cin >> value;

    if (b.balance >= value)
    {
        b.balance -= value;
        cout << "\nYour New Balance:" << b.balance;
    }
    else
    {
        cout << "\nInsufficient Balance";
    }
}
int main()
{
    system("clear");

    Bank b1;
    b1.depositAmount();
    withdraw(b1);
    b1.displayInfo();
 

    return 0;
}

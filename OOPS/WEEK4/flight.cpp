#include <iostream>
using namespace std;

class Flight
{
    int flightNumber;
    char destination[30];
    float distance, fuel;

    void calculateFuel()
    {
        if (distance <= 1000)
            fuel = 500;
        else if (distance > 1000 && distance <= 2000)
            fuel = 1100;
        else if (distance > 2000)
            fuel = 2200;
    }

    public:
        Flight() : distance(500) {}

        void displayInfo()
        {
            cout<<"\n----------------------------------";
            cout<<"\nFlight No:"<<flightNumber;
            cout<<"\nDestination:"<<destination;
            cout<<"\nDistance:"<<distance<<".Km";
            cout<<"\nFuel:"<<fuel<<".Liters\n";
        }

        void imformationEntry()
        {
            cout << "Enter Flight No:";
            cin >> flightNumber;
            cout << "Enter Destination:";
            cin >> destination;
            cout << "Enter Distance:";
            cin >> distance;

            calculateFuel();
            displayInfo();
        }
};

int main()
{
    Flight f1;
    system("clear");
    f1.imformationEntry();
    return 0;
}
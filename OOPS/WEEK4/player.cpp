
#include <iostream>
using namespace std;

int playerCount = 0;
class Player
{
    char playerCode[10], name[20];

public:
    int matchPlayed, totalRuns, notOut;

    Player()
    {
        matchPlayed = 0;
        totalRuns = 0;
        notOut = 0;
    }
    void readData()
    {
        cout << "Enter Player Code:";
        cin >> playerCode;
        cout << "Enter Player Name:";
        cin >> name;
        cout << "Enter number of matches played:";
        cin >> matchPlayed;
        cout << "Enter Total runs:";
        cin >> totalRuns;
        cout << "Enter number of times not out:";
        cin >> notOut;
    }

    friend void average(Player p)
    {
        float value = (float) p.totalRuns / (p.matchPlayed - p.notOut);
        cout << "\nAverage of player " << p.name << " is: " << value;
    }

    friend void average(Player p[], int n)
    { 
        for (int i = 0; i < n; i++)
        {
            average(p[i]);
        } 
    }

    friend void displayData(Player p[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p[i].totalRuns > p[j].totalRuns)
                {
                    Player p1;
                    p1 = p[i];
                    p[i] = p[j];
                    p[j] = p1;
                }
            }
        }

        cout << "\n-----------------------------------------------------------------------------------";
        cout << "\nPlayerCode\tPlayerName\tMatchesPlayed\tTotal Runs\tNot Out";
        cout << "\n-----------------------------------------------------------------------------------";

        for (int i = 0; i < n; i++)
        {
            cout << "\n"
                 << p[i].playerCode;
            cout << "\t\t" << p[i].name;
            cout << "\t\t" << p[i].matchPlayed;
            cout << "\t\t" << p[i].totalRuns;
            cout << "\t\t" << p[i].notOut;
        }
        cout << "\n-----------------------------------------------------------------------------------";
    }
};

int main()
{
    Player p[10];
    system("clear");

    int choice;
    do
    {

        cout << "\n-----------------------------------------------------------------------------------";
        cout << "\n1.Enter player details";
        cout << "\n2.Display average runs of single player";
        cout << "\n3.Average runs of all players";
        cout << "\n4.Display list of all players sorted order";
        cout << "\n5.Exit\n";

        cin >> choice;

        if (choice == 1)
            p[playerCount++].readData();
        else if (choice == 2)
        {
            int value;
            cout << "Enter player number:";
            cin >> value;
            average(p[value]);
        }
        else if (choice == 3)
        {
            average(p, playerCount);
        }
        else if (choice == 4)
        {
            displayData(p, playerCount);
        }
        else
        {
            cout << "Exit";
        }

    } while (choice != 5);
}
#include <iostream>
using namespace std;



class Calc
{
    char str[20];

public:
    void insert()
    {
        cout << "\nEnter String:";
        cin >> str;
    }

    friend void unionC(Calc c1, Calc c2)
    {
        //c1=alwin
        //c2=alwincrasta
        //newStr=[alwin];
        int c1Len = 0, c2Len = 0, n = 0;
        char newStr[20];

        char ch = c1.str[0];
        while (ch != '\0')
        {

            newStr[n] = ch;
            n++;
            c1Len++;
            ch = c1.str[c1Len];
        }

        ch = c2.str[0];
        //alwincrasta
        while (ch != '\0')
        {
            int found = 0;
            //newStr=[alwin];
            //ch = c
            for (int i = 0; i < n; i++)
            {
                if (newStr[i] == ch)
                {
                    found = 1;
                }
            }
            if (found == 0)
            {
                newStr[n] = ch;
                n++;
            }

            c2Len++;
            ch = c2.str[c2Len];
        }
        newStr[n] = '\0';

        cout << "\nUnion of " << c1.str << " " << c2.str << ":" << newStr;
    }

    friend Calc interC(Calc c1, Calc c2)
    {
        int c1Len = 0, c2Len = 0, n = 0;
        char newStr[20];

        char ch = c1.str[0];
        while (ch != '\0')
        {
            c1Len++;
            ch = c1.str[c1Len];
        }

        ch = c2.str[0];
        while (ch != '\0')
        {

            c2Len++;
            ch = c2.str[c2Len];
        }

        //c1:alwin
        //c2:alwincrasta
        for (int i = 0; i < c1Len; i++)
        {
            //a
            for (int j = 0; j < c2Len; j++)
            {
                // 
                if (c1.str[i] == c2.str[j])
                {
                    newStr[n] = c2.str[j];
                    n++;
                }
            }
        }
        newStr[n] = '\0';

        cout << "\nIntersection:" << newStr;
        return Calc();
    }
};

int main()
{
    Calc c1;
    Calc c2;
    c1.insert();
    c2.insert();

    Calc c3;
    unionC(c1, c2);
    interC(c1, c2);
}

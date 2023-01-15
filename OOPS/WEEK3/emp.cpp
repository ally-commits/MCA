
    #include <iostream>
    using namespace std;

    int n;

    struct employee
    {
        int empNo;
        char empName[20];
        int basic;
        int DA;
        int IT;
        int grossSal;
        int netSal;
    } emp[10];

    void readData()
    {
        cout << "Enter no of employees:";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter emp No:";
            cin >> emp[i].empNo;

            cout << "Enter Employee Name:";
            cin >> emp[i].empName;

            cout << "Enter Basic:";
            cin >> emp[i].basic;
        }
    }

    void calculateNetSal()
    {
        for (int i = 0; i < n; i++)
        {
            emp[i].DA = emp[i].basic * 0.12;
            emp[i].grossSal = (emp[i].basic + emp[i].DA);
            emp[i].IT = emp[i].grossSal * 0.18;
            emp[i].netSal = emp[i].grossSal - (emp[i].DA + emp[i].IT);
        }
    }
    void displayData()
    {
        for (int i = 0; i < n; i++)
        { 
            cout<<"\n--------------------------------------";

            cout << "\nEmp No:" << emp[i].empNo;
            cout << "\nEmp Name:" << emp[i].empName;
            cout << "\nBasic Sal:" << emp[i].basic;
            cout << "\nNet Sal:" << emp[i].netSal;
            cout << "\nDA:" << emp[i].DA;
            cout << "\nIT:" << emp[i].IT;
        }
    }
    int main()
    {
        system("clear");
        readData();
        calculateNetSal();
        displayData();
        cout << endl;
    }
#include<iostream>
using namespace std;

class Calc {
    int arr[10];
    int n;

    public:
        Calc() {

        }
        Calc(int pArr[],int count) {
            n = count;
            for(int i=0;i<count;i++) {
                arr[i] = pArr[i];
            }
        }
        void insert() {
            cout<<"Enter value of n:";
            cin>>n;

            cout<<"Enter array values:";
            for(int i=0;i<n;i++) {
                cin>>arr[i];
            }
        }

        friend Calc intersection(Calc obj1,Calc obj2) {
            int newArr[20],count = 0;

            for(int i=0;i<obj1.n;i++) {
                for (int j = 0; j < obj2.n; j++) {
                    if(obj1.arr[i] == obj2.arr[j]) {
                        newArr[count] = obj1.arr[i];
                        count++;
                    }
                }
            } 

            return Calc(newArr,count);
        }

        friend Calc diffrence(Calc obj1, Calc obj2) {
            int newArr[20], count = 0;

            for (int i = 0; i < obj1.n; i++)
            {
                int found = 0;
                for (int j = 0; j < obj2.n; j++)
                {
                    if (obj1.arr[i] == obj2.arr[j])
                    {
                        found = 1;
                    }
                }
                if(found == 0) {
                    newArr[count] = obj1.arr[i];
                    count++;
                }
            } 

            return Calc(newArr, count);
        }

        void display() {
            cout<<endl;
            for(int i=0;i<n;i++) {
                cout<<arr[i]<<" ";
            }
        }
};


int main() {
    Calc c1,c2,c3,c4;

    c1.insert();
    c2.insert();

    c3 = intersection(c1, c2);
    cout<<"\nIntersection";
    c3.display();

    c4 = diffrence(c1, c2);
    cout << "\nDiffrence";
    c4.display();

    cout<<endl;

    return 0;
}
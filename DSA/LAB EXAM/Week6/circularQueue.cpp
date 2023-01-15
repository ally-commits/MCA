#include<iostream>
using namespace std;

int main(int arr[],int &tail,int maxSize,int &count) {
    if(count == maxSize) {
        cout<<"Overflow";
    } else  {
        arr[tail] = 10;
        tail = (tail + 1) % maxSize;
        count++;
    }
}

int main(int arr[], int &front, int maxSize, int count)
{
    if (count == 0)
    {
        cout << "Underflow";
    }
    else
    {
        // cout<<head;
        front = (front + 1) % maxSize;
        count++;
    }
}
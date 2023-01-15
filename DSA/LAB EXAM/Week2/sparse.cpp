#include<iostream>
using namespace std;

struct sparse {
    int data,row,col;
};

void display(int arr[][10], int n, int m)
{
    cout << "\nMatrix Elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n,m;
    int arr[10][10],newArr[10][10];

    sparse sMat[10]; 
    cout<<"Enter value of n:";
    cin>>n>>m;
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
            if(arr[i][j] != 0) {
                count++;
                sMat[count].data = arr[i][j];
                sMat[count].row = i;
                sMat[count].col = j;
            }
        }
    }

    sMat[0].data = count;
    sMat[0].row = n;
    sMat[0].col = m;

    cout<<endl<<endl;
    for(int i=0;i<sMat[0].data;i++) {
        cout<<sMat[i].row<<" "<<sMat[i].col<<" "<<sMat[i].data<<endl;
    }
    cout<<endl<<endl;

    for (int i = 1; i < sMat[0].data; i++) {
        newArr[sMat[i].row][sMat[i].col] = sMat[i].data;
    }
    count = 1;
    for (int i = 0; i < sMat[0].row; i++)
    {
        for (int j = 0; j < sMat[0].col; j++)
        {
            if (sMat[count].row == i && sMat[count].col == j)
            {
                newArr[i][j] = sMat[count++].data;
            }
            else
            {
                newArr[i][j] = 0;
            }
        }
    }

    cout << "\nRe-Constructed Matrix\n";
    display(newArr, n, m);
}
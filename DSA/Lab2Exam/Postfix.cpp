#include<iostream>
using namespace std;

int checkPriority(char ch) {
    if(ch == '^') 
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else 
        return 0;
}

int isSpecialChar(char ch) {
    if((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 0;
    return 1;
}

void evaluateExp(char exp[]) {
    char stack[30],postFix[30];
    int sPoint=-1,pPoint=-1;

    for(int i=0;exp[i] != '\0';i++) {
        if(exp[i] == '(') {
            stack[++sPoint] = exp[i];
        } else if(exp[i] == ')') {
            while(stack[sPoint] != '(' && sPoint > -1) {
                postFix[++pPoint] = stack[sPoint--];
            }
            sPoint--;
        } else if (isSpecialChar(exp[i])) {
            while (checkPriority(stack[sPoint]) >= checkPriority(exp[i]) && sPoint > -1 && stack[sPoint] != '(') {
                postFix[++pPoint] = stack[sPoint--];
            }
            stack[++sPoint] = exp[i];
        } else {
            postFix[++pPoint]=exp[i];
        }


        cout<<"\n\n"<<exp[i]<<"\t";
        for(int i=0;i<=sPoint;i++) 
            cout<<stack[i];
        cout<<"\t";
        for(int i=0;i<=pPoint;i++) 
            cout<<postFix[i];
            
    }
    while(stack[sPoint] > -1) {
        postFix[++pPoint] = stack[sPoint--];
    }
    postFix[++pPoint] = '\0';

    cout<<"\nExpresssion:"<<postFix<<"\n\n";
}

int main(){
    char arr[30];

    cout<<"Enter Expression:";
    cin>>arr;

    evaluateExp(arr);
}

// a/(b*c)^(d-f)
#include<iostream>
using namespace std;

int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}


int calculate(char ch,int a,int b) {
    if(ch == '+')
        return a + b;
    else if(ch == '-')
        return a - b;
    else if(ch == '*')
        return a * b;
    else if(ch == '/')
        return a / b;

    return a + b;
}

void evaluateExp(string exp[],int count) {
    int stack[20];
    int stackPointer = -1;
    cout<<count;

    for(int i=0;i<count;i++) {
        if(exp[i].length() == 1 && isOperator(exp[i][0])) {
            int b = stack[stackPointer--];
            int a = stack[stackPointer--];

            stack[++stackPointer] = calculate(exp[i][0],a,b);
        } else {
            stack[++stackPointer] = stoi(exp[i]);
        }
    }
    cout<<"\nExpression:"<<stack[0];
}

int main() {
    string exp;
    getline(cin,exp);
    string stringExp[30];
    int count = 0;
    string tempStr;
    for(int i=0;i<exp.length();i++) {
        if(exp[i] == ' ') {
            stringExp[count++] = tempStr;
            tempStr="";
        } else {
            tempStr+=exp[i];
        }
    }
    stringExp[count++] = tempStr;
    evaluateExp(stringExp, count);
    cout<<endl;
}

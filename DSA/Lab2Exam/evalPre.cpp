#include<iostream>
using namespace std;

int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        return 1;
    return 0;
}
int add(char ch,int a,int b) {
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

void evaluate(string str[],int count) {
    int stack[10];
    int stackP = -1;

    for(int i=count-1;i>=0;i--) {
        if(isOperator(str[i][0])) {
            int a = stack[stackP--];
            int b = stack[stackP--];

            stack[++stackP] = add(str[i][0],a,b);            
        } else {
            stack[++stackP] = stoi(str[i]);
        }
    }

    cout<<"\nExpr:"<<stack[0]<<"\n";
}

int main() {
    string exp;
    getline(cin,exp);

    string tempStr;
    string strArr[20];
    int count = 0;
    for(int i=0;i<exp.length();i++) {
        if(exp[i] == ' ') {
            strArr[count++] = tempStr;
            tempStr = "";
        } else {
            tempStr+= exp[i];
        }
    }
    strArr[count++] = tempStr;
    for(int i=0;i<count;i++)
        cout<<strArr[i]<<"-";

    evaluate(strArr,count);
}
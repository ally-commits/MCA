#include<iostream>
using namespace std; 

int checkP(char ch) {
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

int isOperator(char ch) {
    if((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
        return 0;
    }
    return 1;
}

void evaluate(char exp[]) {
    char stack[30],post[30];
    int stackP=-1,postP=-1;
    int n;
    for(n=0;exp[n] != '\0';n++);

    for(int i=n-1;i>=0;i--) {
        if(exp[i] == ')') {
            stack[++stackP] = exp[i];
        } else if(exp[i] == '(') {
            while(stack[stackP] != ')' && stackP > -1) {
                post[++postP] = stack[stackP--];
            }
            stackP--;
        } else if(isOperator(exp[i])) {
            while (checkP(exp[i]) < checkP(stack[stackP]) && stack[stackP] != ')' && stackP > -1) {
                post[++postP] = stack[stackP--];
            }
            stack[++stackP] = exp[i];
        } else {
            post[++postP] = exp[i];
        }
    }

    while(stack[stackP] != ')' && stackP > -1) {
        post[++postP] = stack[stackP--];
    }
    post[++postP] = '\0';
    cout<<"\n\nExpression:"<<"";

    for(int i=postP-1;i>=0;i--) 
        cout<<post[i];
}

int main() {
    char str[30];

    cout<<"Enter the expression:";
    cin>>str;

    evaluate(str);
    cout<<endl;
}
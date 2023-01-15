#include<iostream>
using namespace std;

int checkP(char ch) {
    if(ch == '^') 
        return 4;
    else if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else 
        return 1;
} 
int isSpecialChar(char ch) {
        if((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
                return 0;
        return 1;
}

void evaluateExp(char input[]) {
    char postfix[20],stack[30];
    int postPointer = -1,stackPointer = -1;
    char ch = input[0];
    int count = 0;
    cout<<ch;
    while(ch != '\0') {
        cout<<ch;
        if(ch == '(') {
            stack[++stackPointer] = ch;
        } else if(ch == ')') {
            while(stack[stackPointer] != '(' && stackPointer >= -1) {
                postfix[++postPointer] = stack[stackPointer--];
            }
        } else if(isSpecialChar(ch)) {
            while (checkP(ch) <= checkP(stack[stackPointer]) && stack[stackPointer] != '(' && stackPointer >= -1) {
                postfix[++postPointer] = stack[stackPointer--];
            }
            stack[++stackPointer] = ch;
        } else {
            postfix[++postPointer] = ch;
        }
        ch = input[++count];
        
    }
    while(stackPointer > -1) {
        if(stack[stackPointer] != '(') 
            postfix[++postPointer] = stack[stackPointer--];
    }
    postfix[++postPointer] = '\0';

    cout<<"\nEXPRESSION OUTPUT:";
    cout<<postfix<<endl;
}

int main() {
    char exp[30];
    cout << "Enter the expression:";
    cin >> exp;

    cout<<"THIS";
    evaluateExp(exp);
}
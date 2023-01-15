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
    if((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
        return 0;
    }
    return 1;
}


void evaluate(char input[]){
    char prefix[20],stack[20];
    int stackPointer = -1,prePointer = -1;

    int n;
    for(int i=0;input[i] != '\0';i++);
    
    for(int i=n-1;i>=0;i--) {
        if(input[i] == ')') 
            stack[++stackPointer] = ')';
        else if(input[i] == '(') {
            while(stack[stackPointer] != ')' && stackPointer >= -1) {
                prefix[++prePointer] = stack[stackPointer--];
            }
            stackPointer--;
        } else if(isSpecialChar(input[i])) {
            while(checkP(input[i]) < checkP(stack[stackPointer]) && stack[stackPointer] != ')' && stackPointer >= -1) {
                prefix[++prePointer] = stack[stackPointer--];
            }
            stack[++stackPointer] = input[i];
        } else {
            prefix[++prePointer] = input[i];
        }
    }

    while(stack[stackPointer] != ')' && stackPointer > -1) {
        prefix[++prePointer] = stack[stackPointer--];
    }
    prefix[++prePointer] = '\0';

    for(int i=prePointer;i>=0;i--) {
        cout<<prefix[i];
    }
}

int main(){
    char arr[30];

    cout<<"Enter Expression:";
    cin>>arr;

    evaluate(arr);
}
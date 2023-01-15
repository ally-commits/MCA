#include<iostream>
using namespace std;

int checkPiority(char ch) {
    if(ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else 
        return 0;
}
int isSpecialChar(char ch) {
    if((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
        return 0;
    }
    return 1;
}
void evaluateExp(char exp[],char stack[],char output[]) {
    char ch = exp[0];
    int outputCounter = -1;
    int stackCounter = -1;

    for(int i=0; ch != '\0';i++) { 
        if(ch == '(') {
            stack[++stackCounter] = ch;
        } else if(ch == ')') {
            while(stack[stackCounter] != '(' && stackCounter > -1) {
                output[++outputCounter] = stack[stackCounter--];
            }
            stackCounter--;
        } else { 
            if(isSpecialChar(ch)) { 
                if(i > 0 && stackCounter > -1) { 
                    if(checkPiority(ch) <= checkPiority(stack[stackCounter])) {
                        while(checkPiority(ch) <= checkPiority(stack[stackCounter]) && stack[stackCounter] != '(') {
                            output[++outputCounter] = stack[stackCounter--];
                        }
                        stack[++stackCounter] = ch;
                    } else {
                        stack[++stackCounter] = ch;
                    }
                } else {
                    stack[++stackCounter] = ch;
                }
            } else { 
                output[++outputCounter] = ch;
            }
        }   
        ch = exp[i+1]; 
    } 
    cout<<endl<<"OUTPUT:"<<output<<endl;
}
int main() {
    char exp[30];
    int n;
    char stack[30];
    char output[30];
    cout<<"Enter Expression:";
    cin>>exp;
    evaluateExp(exp,stack,output);
}
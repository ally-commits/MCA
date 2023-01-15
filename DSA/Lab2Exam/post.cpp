#include<iostream>
using namespace std;

int checkP(char ch) {
    if(ch == '^') 
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else 
        return 0;
}

int isSpecial(char ch) {
    if((ch >= 48 && ch <= 57) || (ch >=65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 0;
    
    return 1;
}

void evaluateExp(char exp[]) {
    char stack[30],postfix[20];
    int sPoint=-1,pPoint=-1;

    for(int i=0;exp[i] != '\0';i++) {
        if(exp[i] == '(') {
            stack[++sPoint] = exp[i];
        } else if(exp[i] == ')') {
            while(stack[sPoint] != '(' && sPoint >-1) {
                postfix[++pPoint] = stack[sPoint--];
            }
            sPoint--;
        } else if(isSpecial(exp[i])) {
            while(checkP(exp[i]) <= checkP(stack[sPoint]) && stack[sPoint] != '(' && sPoint > -1) {
                postfix[++pPoint] = stack[sPoint--];
            }
            stack[++sPoint] = exp[i];
        } else {
            postfix[++pPoint] = exp[i];
        }
    }

    while(stack[sPoint] != '(' && sPoint > -1) {
        postfix[++pPoint] = stack[sPoint--];
    }
    postfix[++pPoint] = '\0';

    cout<<"\n\nExre:"<<postfix<<endl;
}


int main(){
    char exp[30];

    cout<<"Enter:";
    cin>>exp;

    evaluateExp(exp);
}
#include<iostream>
using namespace std;

int isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

int calculate(char ch, int a, int b)
{
    if (ch == '+')
        return a + b;
    else if (ch == '-')
        return a - b;
    else if (ch == '*')
        return a * b;
    else if (ch == '/')
        return a / b;

    return a + b;
}
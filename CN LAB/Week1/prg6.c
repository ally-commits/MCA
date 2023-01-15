#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int num1, num2;
    double res = 0;
    char op;
    
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    op = *argv[3];

    if (fork() == 0) {
        printf("Child Process:");
        switch (op) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case 'x':
            res = num1 * num2;
            break;
        case '/':
            res = num1 / num2;
            break;
        default:
            printf("\nInvalid Operator!!");

        }
        printf("Result:%lf", res);
    }
    printf("\n");
}
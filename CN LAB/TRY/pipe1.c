#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define MAXSIZE 30

int main() {
    char str[MAXSIZE];
    char inBuf[MAXSIZE];
    int a;
    int b;
    int p[2],i,digit=0,character=0;

    pipe(p);
    int pid = fork();

    if(pid > 1) {
        printf("Enter String:");
        scanf("%d", &a);

        write(p[1], &a, MAXSIZE);
    } else {
        read(p[0], &b,MAXSIZE);
        size_t i = 0;

        printf("%d", b);
    }
}
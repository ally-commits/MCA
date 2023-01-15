#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

#define MAXSIZE 16

int main() {
    char inBuf[MAXSIZE];
    char str[MAXSIZE];

    int p1[2],p2[2];
    pipe(p1);
    pipe(p2);

    int pid = fork();


    if(pid > 1) {
        printf("Enter String:");
        scanf("%s", inBuf);

        write(p1[1], inBuf, MAXSIZE);


        read(p2[0], str, MAXSIZE);
        printf("FILE CONTENT 2: %s", str);
    } if(pid == 0) {
        read(p1[0], str, MAXSIZE);

        printf("FILE CONTENT: %s", str);

        printf("Enter String CHILD:");
        scanf("%s", inBuf);

        write(p2[1], inBuf, MAXSIZE);
    }
}
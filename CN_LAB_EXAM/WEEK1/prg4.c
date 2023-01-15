#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    char c = *argv[3];

    printf("%d %d %c",a,b,c);
}
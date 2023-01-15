#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int chara,char *charv[]) {
    int a = atoi(charv[1]);
    int b = atoi(charv[2]);

    int c = a+b;
    printf("%d%d\n",c,a);
}
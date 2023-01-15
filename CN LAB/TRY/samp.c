#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int a,b;
    printf("Enter a and b:");
    scanf("%d%d",&a,&b);

    if(fork() == 0) {
        printf("%d%d", a, b);
    }
}   
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main() {
    char writeStr1[20],readStr1[20];
    char writeStr2[20], readStr2[20];

    int p[2];
    int q[2];

    pipe(p);
    pipe(q);

    if(fork() > 0) {
        strcpy(writeStr1, "HEY");
        write(p[1], &writeStr1, 20);

        close(p[1]);

        read(q[0], readStr2, 20);

        printf("%s", readStr2);
    } else {
        read(p[0], readStr1, 20);

        printf("%s\n", readStr1);
    
        strcpy(writeStr2, "HELLO");
        write(q[1], &writeStr2,20);
    }
}
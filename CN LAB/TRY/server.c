#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<string.h>


#define  bufSize 64

int main() {
    int fd;
    char inputMsg[bufSize];
    char newStr[bufSize];

    fd = open("client",O_RDWR);

    read(fd, &inputMsg, sizeof(inputMsg));

    printf("\n%s\n", inputMsg);


    mkfifo("server", 0777);

    strcpy(newStr, "HELLO");
    fd = open("server", O_WRONLY);
    write(fd, &newStr,sizeof(newStr));
    close(fd);
    unlink("server");
}
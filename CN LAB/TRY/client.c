#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<string.h>


#define  bufSize 64

int main() {
    int fd;
    char inputMsg[bufSize];
    char readChar[bufSize];

    int fi = mkfifo("client", 0777);
    if(fi < 0) {
        perror("error");
    }
    fd = open("client",O_WRONLY);

    strcpy(inputMsg, "HEY");
    write(fd, &inputMsg, sizeof(inputMsg));

    close(fd);
    sleep(2);

    open("server", O_RDWR);

    read("server", &readChar, sizeof(readChar));

    printf("\n%s\n", readChar);
    unlink("client");

    return 0;
}
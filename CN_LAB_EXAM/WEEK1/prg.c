#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    char source[20],dest[20];

    int fd = open("new.txt", O_WRONLY |O_CREAT, 0666);
    int fd2 = open("one.txt", O_RDONLY);

    char s;
    while(read(fd2,&s,1)) {
        write(fd,&s,1);
    }
}
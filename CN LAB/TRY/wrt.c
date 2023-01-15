#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main() {
    int fd = open("a.txt", O_WRONLY | O_CREAT, 0777);
    if(fd < 0) {
        printf("FILE NOT FOUND");
        return 0;
    }

    char str[30];
    printf("Enter file name:");
    scanf("%s", str);
    sleep(1);

    write(fd, str,30);

    close(fd);

    if(fork() == 0) {
        fd = open("a.txt", O_RDONLY);
        read(fd, str,30);
        printf("%s", str);
    }
}
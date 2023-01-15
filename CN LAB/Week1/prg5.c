#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
int main() {
    int fd = open("a.txt", O_WRONLY | O_CREAT, 0777);
    if (fd == -1)
    {
        printf("Not able to open a file,check file name\n");
        return 0;
    }
    char str[30];
    printf("Enter Something in the file:");
    scanf("%s", str);
    sleep(1);
    write(fd, str, 30);
    printf("Closing file..");
    sleep(1);
    close(fd);
    int pid = fork();
    if (pid == 0) {
        printf("Child Process: opening file");
        sleep(2);
        fd = open("a.txt", O_RDONLY);
        read(fd, str, 30);
        printf("\n%s\n", str);
    }
    wait(0);
    return 0;
}
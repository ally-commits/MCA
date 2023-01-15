#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>

int main() {
    char filename[20];

    printf("Enter the filename:");
    scanf("%s", filename);

    // strcpy(filename, argv[1]);
    if(fork() == 0) { 
        // strcpy(filename, argv[1]);
        printf("FILE NAME:%s", filename);

        int readFile = open(filename, O_RDONLY);
        // printf("%d\n", readFile);

        ssize_t readNum;
        char buff[20];

        while((readNum = read(readFile,buff,1)) > 0) {
            printf("%c",buff[0]);
        }
        close(readFile);
    }
}
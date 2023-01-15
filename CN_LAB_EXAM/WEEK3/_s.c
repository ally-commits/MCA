#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/stat.h>

int main() {
    //READ FROM CLIENT

    int fd = open("_c", O_RDWR);
    char buff[20]; 
    read(fd, &buff, 20);
    printf("READ COMPLETE: %s", buff);

    close(fd);

    // //WRITE TO CLIENT
    char str[20];
    printf("Enter the String:");
    scanf("%s", str);

    int fi = mkfifo("_s", 0777);
    if(fi < 0) {
        printf("ERROR CREATING FILE");
    }
    int fd2 = open("_s", O_WRONLY);
    write(fd2, str, 20);
    close(fd2);
}
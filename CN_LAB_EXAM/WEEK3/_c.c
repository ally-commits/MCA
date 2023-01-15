#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main() {
    //WRITE TO SEVRER
    int fi = mkfifo("_c", 0777);
    if (fi < 0) {
        printf("Error Creating fifo");
        exit(0);
    }
    int fd = open("_c", O_WRONLY);
    char buff[20];
    printf("Enter the String:");
    scanf("%s", buff);
    int wr = write(fd, buff, 20);
    if(wr < 0) {
        printf("FAILED TO WRITE");
    }
    close(fd);

    sleep(4);
    //READ FROM SERVER
    char rc_buff[20];
    int fd1 = open("_s", O_RDWR);
    read(fd1, &rc_buff, 20);
    printf("RECIVED: %s", rc_buff);
    close(fd1);
}
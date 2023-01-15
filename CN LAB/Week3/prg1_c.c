#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define bufSize 64

int main()
{
    int fd, fi, fd2, nwrite, nread;
    char inputMsg[bufSize + 1];
    char readChar[bufSize + 1];

    fi = mkfifo("prg1_client", 0777);
    if (fi < 0)
    {
        perror("Error creating fifo");
        exit(0);
    }

    fd = open("prg1_client", O_WRONLY);

    printf("Enter a String:");
    scanf("%s", inputMsg);

    nwrite = write(fd, inputMsg, sizeof(inputMsg));

    if (nwrite < 0)
        printf("message write failed");

    close(fd);

    sleep(2);
    fd2 = open("prg1_server", O_RDWR);
    nread = read(fd2, &readChar, sizeof(readChar));
    printf("OUTPUT: %s\n", readChar);

    unlink("prg1_client");

    return 0;
}
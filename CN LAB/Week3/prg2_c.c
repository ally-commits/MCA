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
    char username[bufSize + 1];
    char password[bufSize + 1];
    char readChar[bufSize + 1];

    fi = mkfifo("prg2_client", 0777);
    if (fi < 0)
    {
        perror("Error creating fifo");
        exit(0);
    }

    fd = open("prg2_client", O_WRONLY);

    printf("Enter a username:");
    scanf("%s", username);

    printf("Enter a password:");
    scanf("%s", password);

    nwrite = write(fd, username, sizeof(username));
    nwrite = write(fd, password, sizeof(password));

    if (nwrite < 0)
        printf("message write failed");

    close(fd);

    sleep(2);
    fd2 = open("prg2_server", O_RDWR);
    nread = read(fd2, &readChar, sizeof(readChar));
    printf("OUTPUT: %s\n", readChar);

    unlink("prg2_client");

    return 0;
}
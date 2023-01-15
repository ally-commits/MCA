#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define bufSize 64

int main()
{
    int fd, fi, fd2, nread, i, nwrite, flag = 0, length;
    char username[bufSize + 1];
    char password[bufSize + 1];
    char outputStr[bufSize + 1];
    char usernameValid[] = "alwin";
    char passwordValid[] = "password";

    memset(username, '\0', sizeof(username));
    memset(password, '\0', sizeof(password));
    fd = open("prg2_client", O_RDWR);
    if (fd < 0)
    {
        perror("Error opening fifo");
        exit(0);
    }

    nread = read(fd, &username, sizeof(username));
    nread = read(fd, &password, sizeof(password));
    if (nread > 0) { 

        if (strcmp(username,usernameValid) == 0 && strcmp(password,passwordValid) == 0) {
            strcpy(outputStr, "Welcome alwin");
        } else {
            strcpy(outputStr, "Login Access denied.");
        }
        close(fd);

        fi = mkfifo("prg2_server", 0777);
        if (fi < 0)
        {
            perror("Error creating fifo");
            exit(0);
        }

        fd2 = open("prg2_server", O_WRONLY);
        nwrite = write(fd2, outputStr, sizeof(outputStr));
        close(fd2);
    }
    else
    {
        perror("Error reading ");
    }
    unlink("prg2_server");
    return 0;
}

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
    char readChar[bufSize + 1];
    char outputStr[bufSize + 1];

    memset(readChar, '\0', sizeof(readChar));
    
    fd = open("prg1_client", O_RDWR);
    if (fd < 0)
    {
        perror("Error opening fifo");
        exit(0);
    }

    nread = read(fd, &readChar, sizeof(readChar));
    if (nread > 0) {
        printf("\nReceived Data: %s", readChar);
        length = strlen(readChar);
        for (i = 0; i < length; i++)
        {
            if (readChar[i] != readChar[length - i - 1])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            strcpy(outputStr, "NOT PALINDROME");
        }
        else
        {
            strcpy(outputStr, "PALINDROME");
        }
        close(fd);

        fi = mkfifo("prg1_server", 0777);
        if (fi < 0)
        {
            perror("Error creating fifo");
            exit(0);
        }

        fd2 = open("prg1_server", O_WRONLY);
        nwrite = write(fd2, outputStr, sizeof(outputStr));
        close(fd2);
    }
    else
    {
        perror("Error reading ");
    }
    unlink("prg1_server");
    return 0;
}

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
    int totalAmount, unitConsumed;
 

    fd = open("prg4_client", O_RDWR);
    if (fd < 0)
    {
        perror("Error opening fifo");
        exit(0);
    }

    nread = read(fd, &unitConsumed, sizeof(unitConsumed));


    if (nread > 0) {
        if(unitConsumed <= 50) {
            totalAmount = unitConsumed * 1;
        } else if(unitConsumed <= 100) {
            totalAmount = 50;
            totalAmount += (unitConsumed - 50) * 1.5;
        } else if(unitConsumed <= 200) {
            totalAmount = 125;
            totalAmount += (unitConsumed - 100) *2;
        } else {
            totalAmount = 225;
            totalAmount += (unitConsumed - 200) * 3;
        }
        close(fd);

        fi = mkfifo("prg4_server", 0777);
        if (fi < 0) {
            perror("Error creating fifo");
            exit(0);
        }

        fd2 = open("prg4_server", O_WRONLY);
        nwrite = write(fd2, &totalAmount, sizeof(totalAmount));
        close(fd2);
    }
    else
    {
        perror("Error reading ");
    }
    unlink("prg4_server");
    return 0;
}

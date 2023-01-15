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
    int deposit,year=0;
    int interest;

    // memset(deposit, '\0', sizeof(deposit));
    // memset(year, '\0', sizeof(year));

    fd = open("prg3_client", O_RDWR);
    if (fd < 0)
    {
        perror("Error opening fifo");
        exit(0);
    }

    nread = read(fd, &deposit, sizeof(deposit));
    nread = read(fd, &year, sizeof(year));

    if (nread > 0) {

        printf("%d", deposit);
        if(year == 1) {
            interest = deposit * 0.50;
        } else if(year  == 2) {
            interest = (deposit * 0.06) * 2;
        } else if(year == 3) {
            interest = (deposit * 0.07) * 3;
        } else if(year > 3) {
            interest = (deposit * 0.08) * year;
        }
        close(fd);

        fi = mkfifo("prg3_server", 0777);
        if (fi < 0) {
            perror("Error creating fifo");
            exit(0);
        }

        fd2 = open("prg3_server", O_WRONLY);
        nwrite = write(fd2, &interest, sizeof(interest));
        close(fd2);
    }
    else
    {
        perror("Error reading ");
    }
    unlink("prg3_server");
    return 0;
}

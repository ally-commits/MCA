#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define bufSize 64

int main() {
    int fd, fi, fd2, nwrite, nread;
    int deposit,year, interest;

    fi = mkfifo("prg3_client", 0777);
    if (fi < 0) {
        perror("Error creating fifo");
        exit(0);
    }

    fd = open("prg3_client", O_WRONLY);

    printf("Enter a Deposit:");
    scanf("%d", &deposit);

    printf("Enter a Year:");
    scanf("%d", &year);

    nwrite = write(fd, &deposit, sizeof(deposit));
    nwrite = write(fd, &year, sizeof(year));

    if (nwrite < 0)
        printf("message write failed");

    close(fd);

    sleep(2);
    fd2 = open("prg3_server", O_RDWR);
    nread = read(fd2, &interest, sizeof(interest));
    printf("INTREST: %d\n", interest);
    printf("TOTAL AMOUNT: %d\n", interest + deposit);

    unlink("prg3_client");

    return 0;
}
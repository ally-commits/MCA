#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define bufSize 64

int main() {
    int fd, fi, fd2, nwrite, nread;
    int customerId,unitConsumed, output;

    fi = mkfifo("prg4_client", 0777);
    if (fi < 0) {
        perror("Error creating fifo");
        exit(0);
    }

    fd = open("prg4_client", O_WRONLY);

    printf("Enter a Customer Id:");
    scanf("%d", &customerId);

    printf("Enter a Unit Consumed:");
    scanf("%d", &unitConsumed);
 
    nwrite = write(fd, &unitConsumed, sizeof(unitConsumed));

    if (nwrite < 0)
        printf("message write failed");

    close(fd);

    sleep(2);
    fd2 = open("prg4_server", O_RDWR);
    nread = read(fd2, &output, sizeof(output));

    printf("Customer Id: %d\n", customerId);
    printf("Unit Consumed: %d\n", unitConsumed);
    printf("Total Amount: %d\n", output);

    unlink("prg4_client");

    return 0;
}
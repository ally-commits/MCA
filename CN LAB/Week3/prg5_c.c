#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define bufSize 64

int main() {
    int fd, fi, fd2, nwrite, nread;
    int noOfSeats,totalAmount;
    char source[bufSize], destination[bufSize],name[bufSize],output[bufSize];

    fi = mkfifo("prg5_client", 0777);
    if (fi < 0) {
        perror("Error creating fifo");
        exit(0);
    }

    fd = open("prg5_client", O_WRONLY);

    printf("Enter Name:");
    scanf("%s", name);

    printf("Enter source:");
    scanf("%s", source);

    printf("Enter Destination:");
    scanf("%s", destination);

    printf("Enter No Of Seats:");
    scanf("%d", &noOfSeats);

    nwrite = write(fd, &source, sizeof(source));
    nwrite = write(fd, &destination, sizeof(destination));
    nwrite = write(fd, &noOfSeats, sizeof(noOfSeats));

    if (nwrite < 0)
        printf("message write failed");

    close(fd);

    sleep(2);
    fd2 = open("prg5_server", O_RDWR);
    nread = read(fd2, &output, sizeof(output));
    nread = read(fd2, &totalAmount, sizeof(totalAmount));

    if (totalAmount > 0) {
        printf("Name: %s\n", name);
        printf("%s => %s\n", source, destination);
        printf("No Of Seats: %d\n", noOfSeats);
        printf("Total Amount:%d\n", totalAmount);
    } else {
        printf("%s\n", output);
    }

    unlink("prg5_client");

    return 0;
}
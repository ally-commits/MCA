#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define bufSize 64


struct infoData {
    char source[bufSize];
    char destination[bufSize];
    int availableSeats;
    int amount;
};

int main() {
    struct infoData data[2];

    strcpy(data[0].source,"Udupi");
    strcpy(data[0].destination, "Mangalore");
    data[0].availableSeats = 10;
    data[0].amount = 100;

    strcpy(data[1].source, "Udupi");
    strcpy(data[1].destination, "Bangalore");
    data[1].availableSeats = 20;
    data[1].amount = 750;

    int fd, fi, fd2, nread, i, nwrite, flag = 0, length;
    int totalAmount = 0,seats;
    char outputStr[bufSize] = "Source Destination incorrect";
    char source[bufSize];
    char destination[bufSize];
 

    fd = open("prg5_client", O_RDWR);
    if (fd < 0)
    {
        perror("Error opening fifo");
        exit(0);
    }

    nread = read(fd, &source, sizeof(source));
    nread = read(fd, &destination, sizeof(destination));
    nread = read(fd, &seats, sizeof(seats));

    if (nread > 0) {
        for(i=0;i<2;i++) {
            if (strcmp(source, data[i].source) == 0 && strcmp(destination, data[i].destination) == 0) {
                printf("YE YES");
                if(data[i].availableSeats >= seats) {
                    totalAmount = seats * data[i].amount;
                    data[i].availableSeats -= seats;
                    strcpy(outputStr, "Seats available");
                } else {
                    strcpy(outputStr, "Seats Not Available");
                }
            }
        }
        close(fd);

        fi = mkfifo("prg5_server", 0777);
        if (fi < 0) {
            perror("Error creating fifo");
            exit(0);
        }

        fd2 = open("prg5_server", O_WRONLY);
        nwrite = write(fd2, &outputStr, sizeof(outputStr));
        nwrite = write(fd2, &totalAmount, sizeof(totalAmount));
        close(fd2);
    }
    else
    {
        perror("Error reading ");
    }
    unlink("prg5_server");
    return 0;
}

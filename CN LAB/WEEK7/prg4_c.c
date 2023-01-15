#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 50

struct account
{
    unsigned long int accno;
    int pin;
    float amount;
};

int main()
{
    int sockfd, retval;
    int recedbytes, sentbytes;

    struct sockaddr_in serveraddr;
    char buff[MAXSIZE];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("\nSocket creation error");
        exit(0);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    if (retval == -1)
    {
        printf("connection error");
        exit(-1);
    }

    float arr[3] = {0, 0, 0};
    printf("Enter value of A,B,C:");
    scanf("%f%f%f", &arr[0], &arr[1], &arr[2]);

    sentbytes = send(sockfd, &arr, sizeof(arr), 0);
    if (sentbytes == -1)
    {
        close(sockfd);
        exit(0);
    }
    char str[100];
    recedbytes = recv(sockfd, &str, sizeof(str), 0);
    printf("\nSERVER RESPONSE:%s\n", str);
    close(sockfd);

    return 0;
}
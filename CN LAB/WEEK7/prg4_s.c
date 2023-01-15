#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 50
struct account{
    unsigned long int accno;
    int pin;
    float amount;
};

int main()
{
    int sockfd, newsockfd, retval;
    socklen_t actuallen;

    int recedbytes, sentbytes;
    struct sockaddr_in serveraddr, clientaddr;
    char buff[MAXSIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("\n Socket creation error");
        exit(-1);
    }
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    retval = bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (retval == -1)
    {
        printf("Binding Error");
        close(sockfd);
        exit(0);
    }
    retval = listen(sockfd, 1);
    if (retval == -1)
    {
        close(sockfd);
        exit(0);
    }
    actuallen = sizeof(clientaddr);

    newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &actuallen);
    if (newsockfd == -1)
    {
        close(sockfd);
        exit(0);
    }
    struct account rcvAcc;
    recedbytes = recv(newsockfd, &rcvAcc, sizeof(rcvAcc), 0);
    if (recedbytes == -1) {
        close(sockfd);
        close(newsockfd);
        exit(0);
    }

    char str[100];
    float arr[3] = {0, 0, 0};

    float a = arr[0], b = arr[1], c = arr[2];
    float dif = (b * b) - (4 * a * c);
    if (dif > 0) {
        float r1 = (-b + sqrt(dif)) / (2 * a);
        float r2 = (-b - sqrt(dif)) / (2 * a);
        sprintf(str, "Real & Distinct \nr1 : %.2f\nr2 : %.2f ", r1, r2);
    } else if (dif == 0) {
        float r = (-b) / (2 * a);
        sprintf(str, "Real & roots are imaginary \nr : %.2f", r);
    } else {
        float r1 = (-b) / (2 * a);
        float i1 = sqrt(-dif) / (2 * a);
        sprintf(str, "Imaginary roots \nr1 : %.2f + %.2f i\nr2 : %.2f - %.2f i ", r1, i1, r1, i1);
    }

    sentbytes = send(newsockfd, &str, sizeof(str), 0);
    if (sentbytes == -1) {
        close(sockfd);
        close(newsockfd);
        exit(0);
    } 

    close(newsockfd);
    close(sockfd);

    return 0;
}
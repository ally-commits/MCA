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

int main()
{
    int sockfd, retval;
    int recedbytes, sentbytes;

    struct sockaddr_in serveraddr;
    char buff[MAXSIZE];
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        printf("\nSocket creation error");
        exit(0);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    // if (retval == -1)
    // {
    //     printf("connection error");
    //     exit(-1);
    // }

    int len;
    int i = 0;
    while (i < 5)
    {
        i++;
        printf("Enter String:");
        gets(buff);
        sentbytes = sendto(sockfd, buff, sizeof(buff), 0, (const struct sockaddr *)&serveraddr, sizeof(serveraddr));
        if (sentbytes == -1)
        {
            close(sockfd);
            exit(0);
        }
        recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&serveraddr, &len);
        puts(buff);
        printf("\n");
    }
    close(sockfd);

    return 0;
}
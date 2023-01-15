  #include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 50

int main() {
    int sockfd, newsockfd, retval;
    socklen_t actuallen;

    int recedbytes, sentbytes;
    struct sockaddr_in serveraddr, clientaddr;
    char buff[MAXSIZE];
    int a = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

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
    // retval = listen(sockfd, 1);
    // if (retval == -1)
    // {
    //     close(sockfd);
    //     exit(0);
    // }
    actuallen = sizeof(clientaddr);

    // newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &actuallen);
    // if (newsockfd == -1)
    // {
    //     close(sockfd);
    //     exit(0);
    // }

    int i = 0;
    int len;
    while (i < 5)
    {
        i++;
        recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&clientaddr, &actuallen);
        if (recedbytes == -1)
        {
            close(sockfd); 
            exit(0);
        }
        printf("%s" , buff);
        printf("\nEnter String:");

        scanf("%s",buff);
        sentbytes = sendto(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&clientaddr, len);
        if (sentbytes == -1)
        {
            close(sockfd); 
            exit(0);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}
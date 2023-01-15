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

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd < 0)
        perror("Conf Error");

    struct sockaddr_in serveraddr, clinetaddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int retval = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if(retval < 0)
        perror("Bind Error");

    retval = listen(sockfd, -1);
    if (retval < 0)
        perror("Listen Error");

    socklen_t actuallen = sizeof(clinetaddr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&serveraddr, &actuallen);

    if (newsockfd < 0)
        perror("Accept Error");

    char buff[20];
    char sendBuff[20];
    recv(newsockfd,&buff, sizeof(buff),0);

    printf("Recived String:%s\n", buff);

    printf("Enter String:");
    scanf("%s", sendBuff);

    send(newsockfd, &sendBuff, sizeof(sendBuff),0);

    close(newsockfd);
}
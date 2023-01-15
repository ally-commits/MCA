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
    int sockfd = socket(AF_INET,SOCK_DGRAM, 0);
    struct sockaddr_in serveraddr;

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port=htons(3386);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");


    char buff[20], rev[20];
    printf("Enter String:");
    scanf("%s", buff);


    //SEND
    sendto(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    //RECIVE FROM
    socklen_t len;
    recvfrom(sockfd, rev, sizeof(rev), 0, (struct sockaddr *)&serveraddr, &len);
    printf("STR: %s", rev);
}
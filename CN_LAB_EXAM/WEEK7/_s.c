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
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serveraddr,clientaddr;

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3386);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    socklen_t actualen = sizeof(clientaddr);

    char buff[20], rev[20];
    recvfrom(sockfd, buff, sizeof(buff),0,(struct sockaddr*)&serveraddr, &actualen);

    printf("STR: %s", buff);
    printf("Enter value:");
    scanf("%s", rev);
    
    socklen_t len;
    sendto(sockfd, rev, sizeof(rev), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
}
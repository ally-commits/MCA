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
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Conf create connection");
    }
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int retval = connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if(retval < 0) {
        perror("Connect failed");
    }
    
    char buff[20], rBuff[20];
    printf("Enter String:");
    scanf("%s", buff);

    //SEND
    send(sockfd, buff, sizeof(buff),0);
    
    //RECIVED
    recv(sockfd, rBuff, sizeof(rBuff),0);
    printf("RECIVED FROM SERVER: %s", rBuff);

    // close(sockfd);
}
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

#define buffersize 1000
int main() {
    char source[50],dest[50];
    char buff[buffersize];

    ssize_t readS, writeS;

    printf("Enter source filename:");
    scanf("%s", source);

    int sourceFile = open(source,O_RDONLY);
    if(sourceFile < 0) {
        printf("File not found:");
    } else {
        printf("Enter destination file:");
        scanf("%s", dest);

        int destFile = open(dest, O_WRONLY | O_CREAT,0777);

        while(read(sourceFile, &buff, 1)) {
            write(destFile, &buff, 1);
        }
        close(sourceFile);
        close(destFile);
    }
}
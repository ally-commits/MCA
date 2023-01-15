#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define buffersize 1000

int main() {
    char source[20],dest[20];
    char buffer[buffersize];

    size_t read_in,write_out;
    printf("Enter source file:");
    scanf("%s", source);

    int sourceFile = open(source, O_RDONLY);
    if(sourceFile < 0) {
        printf("File Not Found");
    } else {
        printf("Enter Destination file");
        scanf("%s", dest);

        int destFile = open(dest, O_WRONLY | O_CREAT);
        while((read_in = read(sourceFile, &buffer, buffersize)) > 0) {
            write_out = write(destFile, &buffer, read_in);
        }
        close(sourceFile);
        close(destFile);
    }


}
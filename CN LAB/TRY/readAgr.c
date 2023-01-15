#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {
    char filename[20];
    strcpy(filename, argv[1]);
    
    if(fork()) {
        printf("Enter Filename:");
        scanf("%s", filename);
        strcpy(filename, argv[1]);
    } else {
        strcpy(filename, argv[1]);
        printf("%s", filename);
    }
}
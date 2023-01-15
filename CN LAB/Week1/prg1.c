#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define buffersize 10000

int main() {
    char source[25], dest[25]; 
    char buffer[buffersize];          
    ssize_t read_in, write_out;       
    printf("Enter Source file name:");
    scanf("%s", source); 

    int sourceFile = open(source, O_RDONLY);  
    if (sourceFile < 0) {
        printf("File not found"); 
    } else {
        printf("Enter Dest file name:");
        scanf("%s", dest); 

        int destFile = open(dest, O_WRONLY | O_CREAT);
        while ((read_in = read(sourceFile, &buffer, buffersize)) > 0)
        {
            write_out = write(destFile, &buffer, read_in);
        }
        close(sourceFile);
        close(destFile);
    }
    return 0;
}
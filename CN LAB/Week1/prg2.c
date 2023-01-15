#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filename[50];
    int count = 0;
    int call, fd;
    char buffer[1020];
    strcpy(filename, argv[1]);

    if (fork()) { 
        printf("Enter FileName:");
        scanf("%s", filename);
        strcpy(filename, argv[1]); 
    } else { 
        strcpy(filename, argv[1]);
        printf("FileName: %s\n", filename);
        fd = open(filename, O_RDONLY);
        if (fd == -1) { 
            printf("\nFile Not Found");
            close(fd);
            return 0;
        }
        while (read(fd, buffer, 1) && count < 10) {
            printf("%c", buffer[0]);
            count++;
        }
        close(fd);
    }
    return 0;
}
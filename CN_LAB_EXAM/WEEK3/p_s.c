#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    int arr[10],n;
    int fi = mkfifo("pc",0666);
    int fd = open("pc", O_RDONLY);

    
    read(fd, &n, sizeof(n));
    read(fd, &arr, sizeof(arr));

    for(int i=0;i<n;i++) {
        arr[i] = arr[i] + 10;
        printf("%d ", arr[i]);
    }
 
    int fi2 = mkfifo("ps", 0666);
    int fd2 = open("ps", O_WRONLY);

    write(fd2, &arr, sizeof(arr));
    write(fd2, &n, sizeof(n));
}
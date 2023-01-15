#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    int arr[10], n;
    int arr1[10], n1;
    int fi = mkfifo("pc",0777);
    int fd = open("pc", O_WRONLY);

    printf("Enter n:");
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    write(fd,&n, sizeof(n));
    write(fd,&arr,sizeof(arr));

    int fi2 = mkfifo("ps",0666);
    int fd2 = open("ps", O_RDONLY);

    sleep(2);

    read(fd2, &arr1, sizeof(arr));
    read(fd2, &n1, sizeof(n));

    printf("CHILD PROCESS:");
    for(int i=0;i<n1;i++) {
        printf("%d " , arr1[i]);
    }
}
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main() {
    int arr[10],n;
    int p[2];

    pipe(p);
    int pid = fork();

    if(pid > 1) {
        printf("PARENT PROCESS:");
        printf("Enter n:");
        scanf("%d", &n);

        for(int i=0;i<n;i++) {
            scanf("%d", &arr[i]);
        }

        write(p[1], &n, sizeof(n));
        write(p[1], &arr, sizeof(arr));
    }
    if(pid == 0) {
        read(p[0], &n, sizeof(n));
        read(p[0], &arr, sizeof(arr));

        printf("CHILD PROCESS:");

        for(int i=0;i<n;i++) {
            printf("%d " , arr[i]);
        }
    }

}
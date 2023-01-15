#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>

int main() {
    int arr[10], count;
    int evenArr[10], evenCount;

    int p1[2],p2[2];

    pipe(p1);
    pipe(p2);

    int pid = fork();

    if(pid > 1) {
        printf("Enter array of size:");
        scanf("%d", &count);
        for(int i=0;i<count;i++) {
            scanf("%d", &arr[i]);
        }

        write(p1[1], &arr, sizeof(int) * 10);
        write(p1[1], &count, sizeof(int));
    } else {
        read(p1[0], &evenArr, sizeof(int) * 10);
        read(p1[0], &evenCount, sizeof(int));

        printf("COUNT:%d", evenCount);
        for(int i=0;i<evenCount;i++) {
            printf(" %d ", evenArr[i]);
        }
    }
}
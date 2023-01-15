#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main() {
    int arr[10],n;

    printf("Enter size and array:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    int pid = fork();

    if(pid == 0) {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }

    return 1;
}
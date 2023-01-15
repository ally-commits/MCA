#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pid = fork();
    
    if (pid == 0) {
        int ele;
        int flag = 0;
        printf("Enter the element to search:");
        scanf("%d", &ele);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == ele) {
                printf("Element is found at location %d\n", i);
                flag = 1;
            }
        }
        if (flag == 0)
            printf("Element not found\n");
    }
    if (pid > 0)
        wait(NULL);
    return 0;
}
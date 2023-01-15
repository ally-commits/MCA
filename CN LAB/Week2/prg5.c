#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSGSIZE 16

int main()
{
    int n, count = 0, i, j,ch;

    printf("Enter the value of n:");
    scanf("%d", &n);

    int arr[10][10];

    int p[2];
    int q[2];

    pipe(p);
    pipe(q);
    int pid = fork();

    if (pid > 0)
    {
        printf("Array Elements:");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        write(p[1], &n, sizeof(int));
        write(p[1], &arr, sizeof(int) * n * n);

        wait(0);
        close(p[1]);

        read(q[0], &count, sizeof(int));
        read(q[0], &arr, sizeof(int) * count * count);

        printf("Even Numbers:\n");
        for (i = 0; i < count; i++)
        {
            for (j = 0; j < count; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        read(p[0], &n, sizeof(int));
        read(p[0], &arr, sizeof(int) * n * n);

        printf("Enter value of to multiply:");
        scanf("%d", &ch);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++) {
                arr[i][j] = arr[i][j] * ch;
            } 
        }
        write(q[1], &n, sizeof(int));
        write(q[1], &arr, sizeof(int) * n * n); 
    }
    printf("\n");
}
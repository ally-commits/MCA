#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSGSIZE 16

int main()
{
    int n, count = 0, i;

    printf("Enter the value of n:");
    scanf("%d", &n);

    int arr[10], even[10];

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
            scanf("%d", &arr[i]);
        }

        write(p[1], &n, sizeof(int));
        write(p[1], &arr, sizeof(int) * n);

        wait(0);
        close(p[1]);

        read(q[0], &count, sizeof(int));
        read(q[0], &even, sizeof(int) * count);

        printf("Even Numbers:");
        for (i = 0; i < count; i++)
        {
            printf("%d ", even[i]);
        }
    }
    else
    {
        read(p[0], &n, sizeof(int));
        read(p[0], &arr, sizeof(int) * n);

        for (i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                even[count++] = arr[i];
        }

        write(q[1], &count, sizeof(int));
        write(q[1], &even, sizeof(int) * count);
    }
    printf("\n");
}
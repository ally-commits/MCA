#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        printf("Sorted array is:");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");
    }
    return 0;
}
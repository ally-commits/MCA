#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int n;
    printf("Enter the number:");
    scanf("%d", &n);
    int pid = fork();
    if (pid == 0) {
        for (int i = 1; i <= 10; i++) {
            int res = n * i;
            printf("%d * %d = %d", n, i, res);
            printf("\n");
        }
    }
    if (pid > 0)
        wait(NULL);
    return 0;
}


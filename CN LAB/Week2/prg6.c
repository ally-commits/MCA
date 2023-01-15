#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAXSIZE 16

int main()
{
    char str[MAXSIZE];
    char inBuf[MAXSIZE];
    char outputStr[20];

    int length,flag;
    int p[2], i;
    int q[2];

    pipe(p);
    pipe(q);

    int pid = fork();

    if (pid > 1) {
        printf("Enter String:");
        scanf("%s", str);
        write(p[1], str, MAXSIZE);

        read(q[0], &outputStr, MAXSIZE);

        printf("OUTPUT: %s", outputStr);
    } else if (pid == 0) {

        read(p[0], inBuf, MAXSIZE);
        length = strlen(inBuf);
        for (i = 0; i < length; i++) {
            if (inBuf[i] != inBuf[length - i - 1]) {
                flag = 1;
                break;
            }
        }

        if (flag) {
           strcpy(outputStr, "NOT PALINDROME");
        } else {
           strcpy(outputStr, "PALINDROME");
        }

        write(q[1], &outputStr, MAXSIZE);
    }
    printf("\n");
}

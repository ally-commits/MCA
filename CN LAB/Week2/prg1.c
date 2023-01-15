#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXSIZE 16

int main()
{
    char str[MAXSIZE];
    char inBuf[MAXSIZE];

    int p[2], i, digit = 0, character = 0;

    pipe(p);
    int pid = fork();

    if (pid > 1)
    {
        printf("Enter String:");
        scanf("%s", str);
        write(p[1], str, MAXSIZE);
    }
    else if (pid == 0)
    {

        read(p[0], inBuf, MAXSIZE);

        size_t i = 0;
        while (inBuf[i] != '\0')
        {
            if ((int)inBuf[i] >= 48 && (int)inBuf[i] <= 57)
                digit++;
            else
                character++;
            i++;
        }

        printf("DIGIT COUNT: %d", digit);
        printf("\nCHAR COUNT: %d", character);
    }
    printf("\n");
}

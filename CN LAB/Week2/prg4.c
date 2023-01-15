#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSGSIZE 16

struct student
{
    int regno, m1, m2, m3;
};
int main()
{
    int n, total = 0, i, avg;
    char *grade;
    char readGrade[2];
    struct student s1;

    int p[2];
    int q[2];

    pipe(p);
    pipe(q);
    int pid = fork();

    if (pid > 0)
    {
        printf("Enter Student RegNo, M1,M2,M3:");
        scanf("%d%d%d%d", &s1.regno, &s1.m1, &s1.m2, &s1.m3);

        write(p[1], &s1, sizeof(int) * 4);

        read(q[0], readGrade, 2);
        printf("Grade: %s", readGrade);
    }
    else
    {
        read(p[0], &s1, sizeof(int) * 4);
        total = s1.m1 + s1.m2 + s1.m3;
        avg = total / 3;
        if (avg > 90)
            grade = "A+";
        else if (avg > 80)
            grade = "A";
        else if (avg > 70)
            grade = "B";
        else if (avg > 60)
            grade = "C";
        else if (avg > 50)
            grade = "E";
        else
            grade = "F";

        write(q[1], grade, 2);
    }
    printf("\n");
}
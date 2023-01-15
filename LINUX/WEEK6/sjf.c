#include <stdio.h>

int main()
{
    int burstTime[10], n, waitingTime[10], i, j, avgW = 0, avgT = 0, temp;

    printf("Enter No of Process:");
    scanf("%d", &n);

    printf("\nEnter Process Burst Time:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (burstTime[i] < burstTime[j])
            {

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }
    waitingTime[0] = 0;
    for (i = 0; i < n; i++)
    {
        waitingTime[i + 1] = waitingTime[i] + burstTime[i];
    }

    printf("\n\nProcess  BurstTime\tWaitingTime\tTurnAroundTime\n");
    printf("----------------------------------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        avgW = avgW + waitingTime[i];
        avgT = avgT + waitingTime[i + 1];

        printf("%d\t   ", i + 1);
        printf("%d\t\t", burstTime[i]);
        printf("%d\t\t", waitingTime[i]);
        printf("%d\t\t", waitingTime[i + 1]);
    }
    printf("\nAverage Waiting Time: %f", (float)avgW / n);
    printf("\nAverage Turn Around Time: %f\n", (float)avgT / n);

    return 0;
}

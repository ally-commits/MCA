#include <stdio.h>

int main()

{
    int n, burstTime[20], watingTime[20], tat[20], avwt = 0, avtat = 0, i, j;
    printf("Enter total number of process:");
    scanf("%d", &n);

    printf("\nEnter Process Burst Timen:");
    for (i = 0; i < n; i++) { 
        scanf("%d", &burstTime[i]);
    }
    watingTime[0] = 0;
    for (i = 1; i < n; i++) {
        watingTime[i] = 0;
        for (j = 0; j < i; j++)
            watingTime[i] += burstTime[j];
    }

    printf("\nProcess\tBurstTime\tWaitingTime\tTurnaroundTime");

    for (i = 0; i < n; i++) {
        tat[i] = burstTime[i] + watingTime[i];
        avwt += watingTime[i];
        avtat += tat[i];
        printf("\n  %d\t%d\t\t%d\t\t%d", i + 1, burstTime[i], watingTime[i], tat[i]);
    }

    avwt = avwt /  n;
    avtat = avwt / n;
    printf("\nAverage Waiting Time:%d", avwt);
    printf("\nAverage Turnaround Time:%d\n", avtat);

    return 0;
}
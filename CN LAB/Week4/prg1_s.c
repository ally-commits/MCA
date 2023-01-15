#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 32
#define ARRAYSIZE 5

void die(char *s)
{
    perror(s);
    exit(1);
}

struct msgbuf
{
    long mtype;
    int arr[ARRAYSIZE];
};

int main()
{
    int msqid;
    int n, i;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    struct msgbuf sbuf;
    struct msgbuf srec;
    size_t buflen;
    key = 1226;
    if ((msqid = msgget(key, msgflg)) < 0)
        die("msgget");

    sbuf.mtype = 1;
    printf("Enter array %d elements:", ARRAYSIZE);
    for (i = 0; i < ARRAYSIZE; i++)
    {
        scanf("%d", &sbuf.arr[i]);
    }
    buflen = MAXSIZE;

    if (msgsnd(msqid, &sbuf, buflen, IPC_NOWAIT) < 0)
    {
        printf("%d, %ld, %d, %ld\n", msqid, sbuf.mtype, n, buflen);
        die("msgsnd");
    }
    else
        printf("Message Sent\n");

    if ((msqid = msgget(1227, 0666)) < 0)
        die("msgget()");

    if (msgrcv(msqid, &srec, MAXSIZE, 1, 0) < 0)
        die("msgrcv");

    printf("Sorted Array Elements: ");
    for (i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d ", srec.arr[i]);
    }
    printf("\n");
    exit(0);
}
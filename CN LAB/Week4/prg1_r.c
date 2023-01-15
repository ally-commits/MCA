#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 32
#define ARRAYSIZE 5

void die(char *s)
{
    perror(s);
    exit(1);
}

typedef struct msgbuf
{
    long mtype;
    int arr[ARRAYSIZE];
};

int main()
{
    int msqid, i, j, temp;
    key_t key;
    struct msgbuf rcvbuffer;
    int msgflg = IPC_CREAT | 0666;
    key = 1226;
    size_t buflen;

    if ((msqid = msgget(key, 0666)) < 0)
        die("msgget()");

    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
        die("msgrcv");

    printf("Array elements:\n");
    for (i = 0; i < ARRAYSIZE; i++)
    {
        for (j = 0; j < ARRAYSIZE; j++)
        {
            if (rcvbuffer.arr[i] < rcvbuffer.arr[j])
            {
                temp = rcvbuffer.arr[i];
                rcvbuffer.arr[i] = rcvbuffer.arr[j];
                rcvbuffer.arr[j] = temp;
            }
        }
    }

    if ((msqid = msgget(1227, msgflg)) < 0)
        die("msgget");

    buflen = MAXSIZE;
    if (msgsnd(msqid, &rcvbuffer, buflen, IPC_NOWAIT) < 0)
    {
        printf("%d, %ld, %d, %ld\n", msqid, rcvbuffer.mtype, ARRAYSIZE, buflen);
        die("msgsnd");
    }
    else
        printf("Message Sent Sorted\n");
    printf("\n");
    return 0;
}

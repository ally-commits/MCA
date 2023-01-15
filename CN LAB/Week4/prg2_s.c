#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20

void die(char *s)
{
    perror(s);
    exit(1);
}

struct msgbuf
{
    long mtype;
    int num1;
    int num2;
    char opr;
};

int main()
{
    int msqid;
    int n, i;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    struct msgbuf sbuf;
    size_t buflen;
    key = 1228;
    if ((msqid = msgget(key, msgflg)) < 0)
        die("msgget");

    sbuf.mtype = 1;

    printf("Enter operation symbol and 2 numbers:");
    scanf("%c%d%d", &sbuf.opr, &sbuf.num1, &sbuf.num2);

    buflen = MAXSIZE;

    if (msgsnd(msqid, &sbuf, buflen, IPC_NOWAIT) < 0) {
        printf("%d, %ld, %d, %ld\n", msqid, sbuf.mtype, n, buflen);
        die("msgsnd");
    } else
        printf("Message Sent\n");

    if ((msqid = msgget(1227, msgflg)) < 0)
        die("msgget()");

    if (msgrcv(msqid, &sbuf, MAXSIZE, 1, 0) < 0)
        die("msgrcv");

    printf("OUTPUT: %d\n", sbuf.num1);
    exit(0);
}
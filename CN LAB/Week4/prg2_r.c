#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

void die(char *s)
{
    perror(s);
    exit(1);
}

struct msgbuf {
    long mtype;
    int num1;
    int num2;
    char opr;
};

int main()
{
    int msqid, i, j, temp;
    key_t key;
    struct msgbuf rcvbuffer;
    int msgflg = IPC_CREAT | 0666;
    key = 1228;
    size_t buflen;

    if ((msqid = msgget(key, 0666)) < 0)
        die("msgget()");

    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
        die("msgrcv");

    int sum = 0;
    if (rcvbuffer.opr == '+')
        sum = rcvbuffer.num1 + rcvbuffer.num2;
    else if (rcvbuffer.opr == '-')
        sum = rcvbuffer.num1 - rcvbuffer.num2;
    else if (rcvbuffer.opr == '*')
        sum = rcvbuffer.num1 * rcvbuffer.num2;
    else if (rcvbuffer.opr == '/')
        sum = rcvbuffer.num1 / rcvbuffer.num2;

    if ((msqid = msgget(1227, msgflg)) < 0)
        die("msgget");

    rcvbuffer.num1 = sum;
    if (msgsnd(msqid, &rcvbuffer, MAXSIZE, IPC_NOWAIT) < 0) {
        die("msgsnd");
    }
    else
        printf("Message Sent\n");
    printf("\n");

    return 0;
}
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<unistd.h>

struct buff {
    long mtype;
    int value;
};

int main() {
    key_t key = 100;
    int msgid = msgget(key,IPC_CREAT | 0666);

    struct buff b;
    b.mtype = 1;
    b.value = 999;

    msgsnd(msgid, &b, sizeof(b), IPC_NOWAIT);
    printf("SENT");

    key_t key1 = 1001;
    int msgid2 = msgget(key1, IPC_CREAT | 0666);

    struct buff b1; 

    msgrcv(msgid2, &b1, sizeof(b1), 1,0);
    printf("RECIVED %d:", b1.value);

    return 1;
}
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct buff {
    long mtype;
    int value;
};

int main() {
    struct buff b;
    key_t key = 100;
    int msgid = msgget(key, IPC_CREAT | 0666);

    msgrcv(msgid, &b, sizeof(b),1,0);

    printf("RECIVED");
    printf("%d", b.value);

    struct buff b1;
    key_t key1 = 1001;
    int msgid2 = msgget(key1, IPC_CREAT | 0666);

    b1.mtype=1;
    b1.value = 888;
    msgsnd(msgid2, &b1, sizeof(b1),IPC_NOWAIT);

    printf("SENT"); 

    return 0;
}
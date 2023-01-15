#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msgbuf {
    long mtype;
    int value;
};

int main() {
    key_t key = 1000;

    int msgid = msgget(key, IPC_CREAT | 0666);
    if(msgid < 0) {
        perror("Error sending file");
    }
    struct msgbuf _r;
    struct msgbuf _s;

    int fd = msgrcv(msgid, &_r, sizeof(_r),1,0);
    if(fd < 0) {
        perror("Error receinving");
    } 

    printf("%d", _r.value);

    key_t key2 = 1002;
    int msgid2 = msgget(key2, IPC_CREAT | 0666);
    if(msgid2 < 0)
        perror("Error creting p2");

    printf("ENTER N:");
    scanf("%d", &_s.value);

    _s.mtype = 1;

    int fd2 = msgsnd(msgid2, &_s, sizeof(_s), IPC_NOWAIT);
    if(fd2 < 0) 
        perror("Error sending item");
    else
        printf("Send data");
    return 0;
}
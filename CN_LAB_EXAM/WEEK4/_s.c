#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

struct msgbuf {
    long mtype;
    int value;
};

int main() {
    key_t key = 1000; 

    int msgid = msgget(key,IPC_CREAT | 0666);
    if(msgid < 0) {
        perror("Error Creating...");
    }
    struct msgbuf _s;

    struct msgbuf _r;
    _s.mtype = 1;
    _s.value = 10101;

    int fd = msgsnd(msgid,&_s,sizeof(_s), IPC_NOWAIT);
    if(fd < 0) {
        perror("Error Sending");
    }   



    key_t key2 = 1002;

    int msgid2 = msgget(key2, IPC_CREAT | 0666);

    if(msgid2 < 0)
        perror("Erorr in sendder");


    int fd2 = msgrcv(msgid2, &_r, sizeof(_r), 1,0);
    if(fd2 < 0)
        printf("BAD VALUE");
    else
        printf("RECIVED");

    printf("GOT VALUE: %d", _r.value);

    return 0;
}
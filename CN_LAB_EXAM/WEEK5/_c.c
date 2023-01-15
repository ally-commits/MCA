#include<stdio.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/shm.h>


struct data {
    int sendVal;
    int revVal;
};

int main() {
    struct data *d;
    int key = ftok("array1", 34);
    int shmid = shmget(key, sizeof(d), IPC_CREAT | 0666);

    d = shmat(shmid,NULL,0);

    printf("ENTER SENDING VALUE:");
    scanf("%d", &d->sendVal);

    printf("RECIVED VALUE: %d", d->revVal);

    shmdt(d);
}

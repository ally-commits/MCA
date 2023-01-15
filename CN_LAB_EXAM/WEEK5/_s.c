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

    d = shmat(shmid, NULL,0);

    printf("RECIVED VALUE: %d", d->sendVal);

    // printf("ENTER SENDING VALUE:");
    // scanf("%d", &d->revVal);
    // shmdt(d);
    // shmctl(shmid, IPC_RMID, NULL);
}
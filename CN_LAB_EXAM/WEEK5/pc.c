#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

struct buff {
    int value;
};

int main() {
    struct buff *b;
    int key = ftok("arr", 100);

    int shmid = shmget(key, sizeof(b),IPC_CREAT | 0666);

    b = shmat(shmid, NULL,0);
 
    printf("%d",b->value);

    struct buff *b1;
    int key1 = ftok("arr1", 1001);

    int shmid1 = shmget(key1, sizeof(b1), IPC_CREAT | 0666);

    b1 = shmat(shmid1, NULL, 0);

    b1->value = 199;
    printf("SENT");
}
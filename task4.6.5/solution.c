#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/ipc.h>

int main(int c, char *v[]){
    key_t key;
    int* shmseg1 = (int*) shmat(atoi(v[1]), NULL, SHM_RDONLY);
    int* shmseg2 = (int*) shmat(atoi(v[2]), NULL, SHM_RDONLY);
    int shmid = shmget(key, sizeof(int)*100, IPC_CREAT);
    int* rshmseg = (int*)shmat(shmid, NULL, NULL);
    int i;
    for(i =0; i < 100; i++)
        rshmseg[i] = shmseg1[i] + shmseg2[i];
    shmdt(shmseg2);
    shmdt(shmseg1);
    printf("%d\n", shmid);
    shmdt(rshmseg);
}
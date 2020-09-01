#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int c, char *v[]){
    key_t key;
    
    key = ftok(v[0], getpid());
    
    int* shmseg1 = (int*) shmat( shmget(atoll(v[1]), sizeof(char)*1000, 0600)  , NULL, 0600);
    int* shmseg2 = (int*) shmat(shmget(atoll(v[2]), sizeof(char)*1000, 0600), NULL, 0600);
    int shmid = shmget(key, sizeof(char)*1000,  IPC_CREAT | 0666);
    int* rshmseg = (int*)shmat(shmid, NULL, 0);
    int i;
    for(i =0; i < 100; i++)
        rshmseg[i] = shmseg1[i] + shmseg2[i];
    shmdt(shmseg2);
    shmdt(shmseg1);
    printf("%d\n", key);
    shmdt(rshmseg);
}
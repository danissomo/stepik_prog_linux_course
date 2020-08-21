#define _DEFAULT_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <stdlib.h>

int rec(const char *pid ){
    int count =0, i=0;
    char procdir[256];
    char * ps = calloc(128, sizeof(char));

    procdir[0]= '\0';
    sprintf(procdir, "/proc/%s/task/%s/children", pid, pid);
    FILE * fd =fopen(procdir, "rd");
    

    while( fscanf(fd, "%s",ps )!=EOF){
        count++;
        count += rec(ps);
    }
    fclose(fd);
    return count;
}

int main(int argc, char *argv[]){

    printf("%d\n", rec(argv[1]));
    return 0;
}


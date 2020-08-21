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

const int get_ps_ppid(const char * pid){
    char procdir[256];
    procdir[0]= '\0';

    strcat(procdir, "/proc/");
    strcat(procdir, pid);
    strcat(procdir, "/stat");

    FILE * fd =fopen(procdir, "rd");
    if(fd ==NULL) return -1;

    int ppid;
    fscanf(fd, "%*d %*s %*c %d", &ppid);
    
    return ppid;

}
int main(int argc, char *argv[]){
    char procdir[256];
    procdir[0]= '\0';
    sprintf(procdir, "/proc/%s/task/%s/children", argv[1], argv[1]);
    FILE * fd =fopen(procdir, "rd");
    int i=0;
    while( fscanf(fd, "%*s")!=EOF)i++;
    printf("%d\n", i);
    return 0;
}


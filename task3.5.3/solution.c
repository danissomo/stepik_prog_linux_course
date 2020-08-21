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
    int ppid  = get_ps_ppid(argv[1]);
    printf("%s\n", argv[1] );
    while (ppid!=0)
    {
        printf("%d\n", ppid);
        char buf[128];
        buf[0]='\0';
        sprintf(buf, "%d", ppid);
        ppid = get_ps_ppid( buf );
    }

    return 0;
}


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

const char *get_ps_name(const char * pid){
    char procdir[256];
    procdir[0]= '\0';

    strcat(procdir, "/proc/");
    strcat(procdir, pid);
    strcat(procdir, "/stat");

    FILE * fd =fopen(procdir, "rd");
    if(fd ==NULL) return "";

    char tmp[256];
    char* psname = calloc(256,sizeof(char));
    fscanf(fd, "%*d %s", tmp);
    int i =1;
    for( i =1 ; i< strlen(tmp)-1;i++)
        psname[i-1]=tmp[i];

    psname[strlen(tmp)-2] = '\0';
    return psname;

}
int main(){
    
    struct dirent **namelist;
    int n;

    n = scandir("/proc", &namelist, NULL, alphasort);
    if (n == -1) {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    int count=0;

    while (n--) {
        const char * ps_name=get_ps_name(namelist[n]->d_name);
        if(strcmp("genenv", ps_name)==0) count++ ;

        //if(strcmp("", ps_name)==0) continue;
        //printf("%s\n", ps_name);

        free(namelist[n]);
        
    }

    free(namelist);
    printf("%d\n", count);

    return 0;
}


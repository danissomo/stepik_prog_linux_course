#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    FILE* fd = fopen("/proc/self/stat", "rd");
    int  ppid;
    fscanf(fd, "%*d %*s %*c %d", &ppid );
    fclose(fd);
    printf("%d\n", ppid);
    return 0;
}
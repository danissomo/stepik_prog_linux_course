#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#define MAX 8192
int main(int argc, char* argv[]){
    char com[128];
    sprintf(com, "%s %s", argv[1], argv[2]);
    FILE * fd  = popen(com, "r");
    char tmp;
    int count= 0;
    while((tmp = fgetc(fd)) != EOF )
        if(tmp == '0') count++;
    pclose(fd);
    printf("%d\n", count);

}
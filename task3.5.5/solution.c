#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int pid = fork();
    if(!pid){
        setsid();
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        return 0;
    }else{
        printf("%d\n", pid);
        return 0;
    }
}
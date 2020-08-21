#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("%d\n", getpid());
    setsid();
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    sleep(100);
    return 0;
}
   
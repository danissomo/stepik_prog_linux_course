#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_hndlr(int signo){
    exit(EXIT_SUCCESS);
}

int main(){
    signal(SIGURG, sig_hndlr);
    printf("%d\n", getpid());
    setsid();
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    sleep(100);
    return 0;
}
   
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int count1 = 0, count2 =0; 
void sig_hndlr_usr1(int signalno){
    count1++;
}
void sig_hndlr_usr2(int signalno){
    count2++;
}
void sig_term( int signalno){
    printf("%d %d\n", count1, count2);
    exit(EXIT_SUCCESS);
}
int main(){

    signal(SIGUSR1, sig_hndlr_usr1);
    signal(SIGUSR2, sig_hndlr_usr2);
    signal(SIGTERM, sig_term);
    for(;;);
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    char buff[32];
    
    int read1 = 1, read2 = 1;
    int retval, sum = 0;
    int in1 = open("in1", O_NONBLOCK | O_RDONLY), in2 = open("in2", O_NONBLOCK | O_RDONLY);

    int ndfs;
    if(in1 > in2) ndfs = in1+1;
    else ndfs = in2 +1;
    while(read1!=EOF && read2!=EOF){
        struct timeval tv;
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        fd_set fdset;
        FD_SET(in1, &fdset);
        FD_SET(in2, &fdset);
        int retv = select(ndfs, &fdset, NULL, NULL, &tv);
        if(retv == 0 || retv == -1) continue;
        if(FD_ISSET(in1, &fdset)) {
            read1 = read(in1, buff, 31);
            if(read1 == EOF) continue;
            buff[read1+1] = '\0';
            sum += atoi(buff);
        }

        if(FD_ISSET(in1, &fdset)) {
            read2 = read(in1, buff, 31);
            if(read2 == EOF) continue;
            buff[read2+1] = '\0';
            sum += atoi(buff);
        }
        FD_ZERO(&fdset);
    }
    printf("%d\n", sum);
    return(0);
}
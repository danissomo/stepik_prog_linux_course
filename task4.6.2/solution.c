#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    int read1 = 1, read2 = 1;
    int retval, sum = 0;
    int in1 = open("in1", O_NONBLOCK | O_RDONLY), in2 = open("in2", O_NONBLOCK | O_RDONLY);
    char buff[100];

    while ((read1 != EOF) || (read1 != EOF) ){

        if(read1 == EOF) goto in2check;
        retval = select(1, &in1, NULL, NULL, &tv);
        if (retval == -1)
            perror("select()");
        else if (retval){
            //printf("Data is available now.\n");
            read1 = read(in1, buff, retval);
            if(read1 == EOF) continue;
            buff[retval] = '\0';
            sum += atoi(buff);
        }
        
        in2check:
        if(read2==EOF) continue;
        retval = select(1, &in2, NULL, NULL, &tv);
        if (retval == -1)
            perror("select()");
        else if (retval){
            //printf("Data is available now.\n");
            read2 = read(in1, buff, retval);
            if(read2 == EOF) continue;
            buff[retval] = '\0';
            sum += atoi(buff); 
        }
            
    }
    
   
    return(0);
}
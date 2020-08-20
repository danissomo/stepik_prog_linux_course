#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>
void (*hello_msg)(const char *);

bool init_lib(){
    printf("g");
    void *hdl = dlopen("libHello.so", RTLD_LAZY);
    if(NULL == hdl)
        return false;

    hello_msg = (void (*)(const char*))dlsym(hdl, "hello_msg"); 
    if(NULL == hello_msg)
        return false;
    return true;
}

int main(){

    if(init_lib())
        hello_msg("abcd");
    else 
        printf("error\n");
    return 0;
}

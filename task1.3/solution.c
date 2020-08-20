#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>
#include <string.h>
int (*func)(int);

bool init_lib(const char* dll , const char* f){
    void *hdl = dlopen(dll, RTLD_LAZY);
    if(NULL == hdl)
        return false;

    func = (int (*)(int))dlsym(hdl,f ); 
    if(NULL == func){
        
        return false;
    }
    return true;
}

int main(int argc, char* argv[]){
     if(init_lib(argv[1], argv[2]))
        printf("%d\n", func(atoi(argv[3])));

}
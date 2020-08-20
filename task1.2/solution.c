#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>
int stringStat(const char *string, size_t multiplier, int *count){
    size_t i=0;
    while(string[i]!='\0')
        i++;
    (*count)++;
    return i*multiplier;
    dlopen
}

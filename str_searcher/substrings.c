#include <stdio.h>
#include <string.h>
#include "substrings.h"

int substrings(char* str,char* substr,char** ptr,int n){
    int i = 0;
    while(strstr(str,substr)){
        ptr[i] = strstr(str,substr);
        str = (strstr(str,substr) + 1);
        i++;
        if(i == n) return -1;
    }
    return i;
}
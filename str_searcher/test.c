#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void){
    char* a = "Atom";//malloc(20*sizeof(char));
    char** np;

    np = &a;
    printf("%p %p\n",*np,a);
    printf("%s %s\n",*np+1,a);
    printf("%s %s\n",*np+2,a); 
    printf("%s %s\n",*np+3,a);  
}

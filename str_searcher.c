#include <stdio.h>
#include <string.h>
#include "substrings.h"

int main(void) {
    char* a = "Rokokokommode";
    char* b = "oko";
    char* p[10];
    int k, pos; 
    
    k = substrings(a,b,p,10);
    if(k < 0){
        printf("");
	    return -1;
    }
    printf("\nDen Substring '%s' gab es %d mal in '%s':\n",b,k,a);
    for (int i = 0; i < k; i++){
        pos = (p[i] - a) + 1;
        printf("Fund %d: Adresse %p oder Stelle %d\n",i+1,p[i],pos);
    }
    printf("\n");
    return 0;
}

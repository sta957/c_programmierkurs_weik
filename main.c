#include <stdio.h>
#include "expand.h"

int main(int argc, char *argv[]){
FILE * file;
char *filename;

    if(argc != 1){
        filename = argv[1];
        file = fopen(filename,"r");
    }else{
        file = stdin;
    }

    //filename = "/Users/statim/Desktop/weik/expand/test.txt"; // for testing purposes
    
    printf("\n\n");
    expand(file);
    printf("\n\n");
}
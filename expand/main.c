#include <stdio.h>
#include "expand.h"

int main(int argc, char *argv[]){
    
    char* filename = argv[1];

    //filename = "/Users/statim/Desktop/weik/expand/test.txt"; // for testing purposes
    
    if (filename == NULL){
        printf("Wahle eine Datei zum einlesen: ");
        scanf("%s",filename);
    }
    printf("\n\n");
    expand(filename);
    printf("\n\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tabsize 8

// programm to read filecontent to cli
int expand(FILE *file){
    char* content;
    //FILE *file;
    int i, t = 0, last, flag;
    //file = fopen(filename,"r");

    while((i = fgetc(file)) != EOF){
        if(last == '\\' && i == 't'){
            for(int space = tabsize - (t % tabsize); space > 0; space--){
                //printf("%d",space); // for debugging purposes
                printf(" ");
            }
            flag = 0;
            last = i;
        }else if(i != 92){
            if(i == 10){
                t = -1;
            }
            putchar(i);
            t++;
            last = i;
        }else if(i == 92){
            last = i;
            if(flag == 92){
                putchar(i);
                flag = 0;
                t++;
            }
            flag = i;
        }
    }

    fclose(file);
    return 0;
}

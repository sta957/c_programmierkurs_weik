#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// programm to read filecontent to cli
int expand(char* filename){
    char* content;
    FILE *file;
    int i, t, last, flag;
    file = fopen(filename,"r");

    while((i = fgetc(file)) != EOF){
        if(last == 92 && i == 116){
            for(int space = 8 - (t % 8); space > 0; space--){
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
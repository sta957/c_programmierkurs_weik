#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// programm to read filecontent to cli
/*int expand(char* filename){
    
    return 0;
}*/

int main(void){
    char* content;
    FILE *file;
    int i, t, last;
    file = fopen("/Users/statim/Desktop/weik/expand/test.txt","r");
    
    printf("\n\n");

    if(file == NULL){
        printf("Wahle eine Datei zum einlesen: ");
        //scanf("%s",&file);
    }else{
        while((i = fgetc(file)) != EOF){
            if(last == 92 && i == 116){
                for(int space = 8 - (t % 8); space > 0; space--){
                    //printf("%d",space); // for debugging purposes
                    printf(" ");
                }
            }else if(i != 92){
                if(last == 10) 
                    t = 0;
                putchar(i);
                t = t + 1;
                last = i;
            }else{
                last = 92;
            }
        }
        fclose(file);
        printf("\n\n");
    }
}

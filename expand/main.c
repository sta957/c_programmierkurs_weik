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
    int i, t, last, flag;
    char* filename;

    filename = "/Users/statim/Desktop/weik/expand/test.txt";
    
    if (filename == NULL){
        printf("Wahle eine Datei zum einlesen: ");
        //scanf("%s",&filename);
    }
    
    file = fopen(filename,"r");
    printf("\n\n");

    while((i = fgetc(file)) != EOF){
        if(last == 92 && i == 116){
            for(int space = 8 - (t % 8); space > 0; space--){
                //printf("%d",space); // for debugging purposes
                printf(" ");
            }
            flag = 0;
            last = i;
        }else if(i != 92){
            if(last == 10) 
                t = 0;
                putchar(i);
                t = t + 1;
                last = i;
        }else if(i == 92){
            last = i;
            if(flag == 92){
                putchar(i);
                flag = 0;
            }
            flag = i;
        }
    }
    fclose(file);
    printf("\n\n");
}

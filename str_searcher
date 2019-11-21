#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n = 5;

// str = inputstring, substr = searched substring, ptr = ??, k = number of found strings
int	substrings(char* str, char* substr, char** ptr, int n){
    char** np[10];
    bool x = false;
    int v = 0;
        for(int i = 0; i < strlen(str); i++){
            if(v < n){
                if(substr[0] == str[i]){
                    for(int t = 0;t < strlen(substr); t++){
                        if(str[i+t] == substr[t]){
                            x = true;
                        }else{ 
                            x = false;
                            break;
                        }
                    }
                    if(x){
                        np[v] = ptr+i;
                        printf("Fund %d:\n",v);
                        printf("\tPointer Adresse: %p\n\tChar Adresse   : %s \n",np[v],*np[v]);
                        v++;
                    } 
                }
            }
        }
    return v;
}

int main(void){
    char* a = malloc(20*sizeof(char));
    char* b = malloc(20*sizeof(char));
    char **p = malloc(20*sizeof(char));
    int anzahl = 0;

    printf("Bitte gebe ein Wort/einen Satz ein: ");
    scanf("%[^\t\n]99s",a);
    printf("Bitte gebe die gesuchte Zeichenkette ein: ");
    scanf("%99s",b);
    printf("\n");
    //printf("Bitte gebe die Obergrenze an Ergebnissen an: ");
    //scanf("%d",&n);
    p = &a;
    anzahl = substrings(a,b,p,n);
    printf("\nDie Zeichenkette '%s' wurde %d mal in '%s' gefunden.\n",b,anzahl,a);
    if(anzahl == n) printf("Das Maximum an Durchläufen wurde erreicht!\n");
    free(a);
    free(b);
    return 0;
}


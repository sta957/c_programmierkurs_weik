#include <stdio.h>
#include "hcp.h"

int main(void){
    int og = 0,i = 0,z = 0,max = 0;
    printf("Geben Sie eine Obergrenze ein:");
    int zahl = scanf("%d",&og);
    if(zahl == 1){
        while(z < og){
            i = hcp(z);
            printf("Die %d brauchte %d Durchläufe.\n",z+1,i);
            z++;
        }
    }else{printf("Keine natürliche Zahl eingegeben!");}
    return 0;
}

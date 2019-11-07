#include <stdio.h>

int og,i,x,z,imax,xmax = 0;

int main(void){
    printf("Geben Sie eine Obergrenze ein:");
    scanf("%d",&og);
    while(z < og){
        x = z;
        i = 0;
        while(x != 1){
            if(x % 2 == 0 && x != 0){
                x = x/2;
                printf("%d \t %d \n",x,i);
            }else{
                x = (3*x)+1;
                printf("%d \t %d \n",x,i);
            }
            i++;
        }
        if(i!=1) printf("Es brauchte %d Durchläufe um von %d auf 1 zu kommen.\n",i,z);
        else printf("Es brauchte %d Durchlauf um von %d auf 1 zu kommen.\n",i,z);
        if(i > imax){imax = i;xmax = z;}
        z++;   
    }
    printf("Es brauchte maximal %d Durchläufe. Die Zahl war die %d.\n",imax,xmax); 
    return 0;
}

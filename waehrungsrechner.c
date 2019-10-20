#include <stdio.h>

float usd,amnt = 0.0;
int whrng = 0;
char *whrng1,*whrng2 = "";

int main(void){
    printf("Wie viele USD bekomme ich für einen Euro?");
    scanf("%f",&usd);
    printf("Was ist Ihre Ausgangswährung? 1=Euro 2=USD:");
    scanf("%d",&whrng);
    if(whrng == 1){
        whrng1 = "Euro";
        whrng2 = "USD";
    }
    else if(whrng == 2){
        whrng1 = "USD";
        whrng2 = "Euro";
    }
    printf("Welchen %s Betrag wollen Sie wechseln?",whrng1);
    scanf("%f",&amnt);
    if(whrng1 == "Euro"){
        amnt = amnt * usd;
    }else{
        amnt = amnt / usd;
    }
    printf("Sie erhalten dafuer %.2f %s\n",amnt,whrng2);
    return 0;
}

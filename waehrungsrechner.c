#include <stdio.h>

float usd,amnt,spd = 0.0;
int whrng = 0;
char *whrng1,*whrng2 = "";

int main(void){
    printf("Wie viele USD bekomme ich für einen Euro?"); //1.11 USD
    scanf("%f",&usd);
    printf("Wie viele SPD bekomme ich für einen Euro?"); //1.51 SPD
    scanf("%f",&spd);
    printf("Was ist Ihre Ausgangswährung? 1=Euro 2=USD 3=SPD:");
    scanf("%d",&whrng);
    switch(whrng){
        case 1: whrng1 = "Euro";break;
        case 2: whrng1 = "USD";break;
        case 3: whrng1 = "SPD";break;
        default: whrng1 = "Euro";
    }
    printf("Welchen %s Betrag wollen Sie wechseln?",whrng1);
    scanf("%f",&amnt);
    switch(whrng){
        case 1: amnt = amnt;break;
        case 2: amnt = amnt / usd;break;
        case 3: amnt = amnt / spd;break;
        default: amnt = amnt;
    }
    printf("Sie erhalten dafuer %.2f Euro\n",amnt);
    return 0;
}

#include<stdio.h>
int main(){
    int a;
    scanf("%i",&a);
    if (a==0) printf("ZERO");    
    if (a==1) printf("ONE");
    if (a==2) printf("TWO");
    if (a==3) printf("THREE");
    if (a==4) printf("FOUR");
    if (a==5) printf("FIVE");
    if (a==6) printf("SIX");
    if (a==7) printf("SEVEN");
    if (a==8) printf("EIGHT");
    if (a==9) printf("NINE");
    if (a<0 || a>9) printf("ERROR");
    return 0;
}
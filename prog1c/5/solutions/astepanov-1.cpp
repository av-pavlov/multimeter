#include "stdio.h"

int main(){
    int n;
    scanf("%d", &n);
    if (n<0 || n>10){
        printf("ERROR");
    }
    if (n==0){
        printf("ZERO");
    }
    if (n==1){
        printf("ONE");
    }
    if (n==2){
        printf("TWO");
    }
    if (n==3){
        printf("THREE");
    }
    if (n==4){
        printf("FOUR");
    }
    if (n==5){
        printf("FIVE");
    }
    if (n==6){
        printf("SIX");
    }
    if (n==7){
        printf("SEVEN");
    }
    if (n==8){
        printf("EIGHT");
    }
    if (n==9){
        printf("NINE");
    }
    return 0;
}
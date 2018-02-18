#include<stdio.h>
int main(){
    int year;
    scanf("%i",&year);
    if (year >=1 && year<=2200){
        if ((year%4==0 && year%100!=0)||(year%400==0))
        printf("LEAP"); else printf("NORMAL");
    }
    else {
        printf("ERROR");
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int Year;
    scanf("%d", & Year);
    if( Year < 1 || Year > 2200){
        printf("ERROR");
    } else{
        if((Year%400==0 ||( Year%4==0 && Year%100!=0))){
            printf("LEAP");
        }else{
            printf("NORMAL");
        }
        }
        return 0;
}
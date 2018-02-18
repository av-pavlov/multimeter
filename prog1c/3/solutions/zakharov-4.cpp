#include <math.h>
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "ru");
    int x;
    scanf("%d", &x);
    if(x >= 1 && x<=100){
        if(x>=5 && x<=20 || x%10==5 || x%10==6 || x%10==7 || x%10==8 || x%10==9 || x%10==0){
            printf("ВАМ %d ЛЕТ", x);
        }else{
            if(x%10==1){
                printf("ВАМ %d ГОД", x);
            }else{
                printf("ВАМ %d ГОДА", x);
            }
        }
    }else{
        printf("ERROR");
    }
}
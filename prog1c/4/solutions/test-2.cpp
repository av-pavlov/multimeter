//#include <stdafx.h>
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale (LC_ALL, "ru");
    int n;
    scanf("%d", &n);
    if (n<1 || n>100){
        printf("ERROR\n");
    } else {
        printf("ÂÀÌ ");
        if(n >=10 && n <=20){
           printf ("%d ËÅÒ\n", n);
        } else {
             if (n % 10 == 1){
                printf("%d ÃÎÄ\n", n);
            } else {
                if (n%10== 2 || n % 10 == 3|| n%10 ==4) {
                    printf("%d ÃÎÄÀ\n", n);
                } else{
                    printf("%d ËÅÒ\n",n);
                }    
            }
        }   
    }
    return 0;
}


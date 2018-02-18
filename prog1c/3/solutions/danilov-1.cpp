#include<stdio.h>
int main(){
    int a;
    scanf("%i",&a);
    if (a==1){
        printf("Вам %i год",a);
    }else{
        if (a>=2 && a<=4){
            printf("Вам %i года",a);
        }else{
            if (a>=5 && a<=20){
                printf("Вам %i лет",a);
            }else{
                if ((a%10)==1){
                    printf("Вам %i год",a);
                }else{
                    if ((a%10)>=2 && (a%10)<=4){
                        printf("Вам %i года",a);
                    }else{
                        printf("Вам %i лет",a);
                    }
                }
            }
        }
    }
    return 0;
}
#include<stdio.h>
int main(){
    int a;
    scanf("%i",&a);
    if (a==1){
        printf("ÂÀÌ %i ÃÎÄ",a);
    }else{
        if (a>=2 && a<=4){
            printf("ÂÀÌ %i ÃÎÄÀ",a);
        }else{
            if (a>=5 && a<=20){
                printf("ÂÀÌ %i ËÅÒ",a);
            }else{
                if ((a%10)==1){
                    printf("ÂÀÌ %i ÃÎÄ",a);
                }else{
                    if ((a%10)>=2 && (a%10)<=4){
                        printf("ÂÀÌ %i ÃÎÄÀ",a);
                    }else{
                        printf("ÂÀÌ %i ËÅÒ",a);
                    }
                }
            }
        }
    }
    return 0;
}
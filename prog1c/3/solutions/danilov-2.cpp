#include<stdio.h>
int main(){
    int a;
    scanf("%i",&a);
    if (a==1){
        printf("��� %i ���",a);
    }else{
        if (a>=2 && a<=4){
            printf("��� %i ����",a);
        }else{
            if (a>=5 && a<=20){
                printf("��� %i ���",a);
            }else{
                if ((a%10)==1){
                    printf("��� %i ���",a);
                }else{
                    if ((a%10)>=2 && (a%10)<=4){
                        printf("��� %i ����",a);
                    }else{
                        printf("��� %i ���",a);
                    }
                }
            }
        }
    }
    return 0;
}
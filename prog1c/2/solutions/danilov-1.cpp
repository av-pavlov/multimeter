#include<stdio.h>
int main(){
    char a;
    scanf("%c",&a);
    if (a>=48 && a<=57){
        printf("DIGIT");
    }else{
        if (a>=65 && a<=90){
            printf("CAPITAL");
        }else{
            if (a>=97 && a<=122){
                printf("LOWERCASE");
            }else{
                printf("NON-ALPHANUMERIC");
            }
        }
    }
    return 0;
}
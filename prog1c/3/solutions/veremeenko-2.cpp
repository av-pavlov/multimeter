#include <math.h>
#include <stdio.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "ru");
    int a;
    scanf("%d",&a);
    if(a>=1 && a<=100){
        if(a%10 >= 2 && a%10 <= 4) {
            if(a <=12 || a>=14) {
                printf ("ÂÀÌ %d ÃÎÄÀ", a);
            }
    }
        if(a%10>=5 && a%10<=9 || a==0) {
            printf ("ÂÀÌ %d ËÅÒ", a);
        }
        if(a%10==1) {
            if(a!=11) {
            printf ("ÂÀÌ %d ÃÎÄ", a);
            }
        }
        if(a >=11 && a<=14) {
            printf ("ÂÀÌ %d ËÅÒ", a);
        }
        if(a == 100) {
            printf ("ÂÀÌ %d ËÅÒ", a);
        }
} else printf("ERROR");
} 
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
                printf ("��� %d ����", a);
            }
    }
        if(a%10>=5 && a%10<=9 || a==0) {
            printf ("��� %d ���", a);
        }
        if(a%10==1) {
            if(a!=11) {
            printf ("��� %d ���", a);
            }
        }
        if(a >=11 && a<=14) {
            printf ("��� %d ���", a);
        }
        if(a == 100) {
            printf ("��� %d ���", a);
        }
} else printf("ERROR");
} 
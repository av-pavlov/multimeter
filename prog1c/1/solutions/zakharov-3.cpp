#include <math.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    int a;
        scanf("%d",&a);
            if (a<1 || a>2200) {
                printf("ERROR");
            }
                if (a%4==0 && a%100 != 0 || a%400 == 0) {
                    printf("LEAP");
                }
                else {
                    printf("NORMAL");
                }
}
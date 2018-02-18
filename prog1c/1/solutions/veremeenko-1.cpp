#include <math.h>
#include <stdio.h>
#include <locale.h>


int main()
{
    int a = 0;
    printf("¬ведите год от 1 до 2200 включительно ");
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
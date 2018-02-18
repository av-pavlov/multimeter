#include <math.h>
#include <stdio.h>
#include <locale.h>


int main()
{
    int a;
    scanf("%c",&a);
    if(a > '0' && a < '9') {
        printf("DIGIT");
    } else if (a > 64 && a < 91) {
        printf("CAPITAL");
    } else if (a > 96 && a < 123) {
        printf("LOWERCASE");
    } else {
        printf("NON-ALPHANUMERIC");
    }
}
#include<stdio.h>
int main () 
{
    char a;
    scanf("%c", &a);
    if (a > 47 && a < 58) {
        printf("DIGIT");
    } else if (a > 64 && a < 91) {
        printf("CAPITAL");
    } else if (a > 96 && a < 123) {
        printf("LOWERCASE");
    } else {
        printf("NON-ALPHANUMERIC");
    }
    return 0;
}

#include<stdio.h>
#include <clocale>
int main () 
{
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("ERROR");
        return 0;
    }
    printf("ÂÀÌ %d ", n);
    if (n % 10 == 1 && n!=11) {
        printf("ÃÎÄ");
    } else if (n % 10 > 1 && n % 10 < 5) {
        printf("ÃÎÄÀ");
    } else {
        printf("ËÅÒ");
    }
    return 0;
}

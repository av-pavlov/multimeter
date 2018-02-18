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
    printf("ВАМ %d ", n);
    if (n % 10 == 1 && n!=11) {
        printf("ГОД");
    } else if (n % 10 > 1 && n % 10 < 5) {
        printf("ГОДА");
    } else {
        printf("ЛЕТ");
    }
    return 0;
}

//Введите с клавиатуры число n и выведите английское название соот-
//ветствующей цифры от 0 до 9, либо ERROR, если число меньше 0 или
//больше 9. Массивы не использовать.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n){
        case 0: printf ("null");
        case 1: printf ("one");
        case 2: printf ("two");
        case 3: printf ("three");
        case 4: printf ("four");
        case 5: printf ("five");
        case 6: printf ("six");
        case 7: printf ("seven");
        case 8: printf ("eight");
        case 9: printf ("nine");
        default: printf ("ERROR");
    }
    return 0;
}
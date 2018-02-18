//Введите с клавиатуры число n и выведите английское название соот-
//ветствующей цифры от 0 до 9, либо ERROR, если число меньше 0 или
//больше 9. Массивы не использовать.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n){
        case 0: printf ("null"); break;
        case 1: printf ("one"); break;
        case 2: printf ("two"); break;
        case 3: printf ("three"); break;
        case 4: printf ("four"); break;
        case 5: printf ("five"); break;
        case 6: printf ("six"); break;
        case 7: printf ("seven"); break;
        case 8: printf ("eight"); break;
        case 9: printf ("nine"); break;
        default: printf ("ERROR");
    }
    return 0;
}
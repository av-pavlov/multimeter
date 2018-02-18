//Введите с клавиатуры число n и выведите английское название соот-
//ветствующей цифры от 0 до 9, либо ERROR, если число меньше 0 или
//больше 9. Массивы не использовать.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n){
        case 0: printf ("ZERO"); break;
        case 1: printf ("ONE"); break;
        case 2: printf ("TWO"); break;
        case 3: printf ("THREE"); break;
        case 4: printf ("FOUR"); break;
        case 5: printf ("FIVE"); break;
        case 6: printf ("SIX"); break;
        case 7: printf ("SEVEN"); break;
        case 8: printf ("EIGHT"); break;
        case 9: printf ("NINE"); break;
        default: printf ("ERROR");
    }
    return 0;
}
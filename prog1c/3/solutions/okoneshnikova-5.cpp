//Напишите программу, которая вводит с клавиатуры возраст n лет и вы-
//водит сообщение ВАМ n ЛЕТ/ГОДА/ГОД, используя правильное слово,
//если 1 ⩽ n ⩽ 100, или ERROR в противном случае.

#include <stdio.h>

int main() {
    int n;
    scanf ("%d", &n);
    if (n>=1 && n<=100) {
        if (n%10==1 && n!=11) {
            printf("ВАМ", n, "ГОД");
        } else {
            printf("ВАМ", n, "ЛЕТ");
        }
    } else {
        printf ("ERROR");
    }
    return 0;
}
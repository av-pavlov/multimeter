// Заменить цифру англ словом

#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("ZERO");
    } else if (n == 1){
        printf("ONE");
    } else if (n == 2){
        printf("TWO");
    } else if (n == 3){
        printf("THREE");
    } else if (n == 4){
        printf("FOUR");
    } else if (n == 5){
        printf("FIVE");
    } else if (n == 6){
        printf("SIX");
    } else if (n == 7){
        printf("SEVEN");
    } else  if (n == 8){
        printf("EIGHT");
    } else if (n == 9){
        printf("NINE");
    } else {
        printf("ERROR");
    }
    return 0;
}
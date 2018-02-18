// Вывод возраста

#include <cstdio>
#include <clocale>

int main () {
    setlocale(LC_ALL, "ru");
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("ERROR");
        return 0;
    }
    printf("ВАМ %d ", n);
    if (n % 10 == 1) {
        printf("ГОД");
    } else if (n % 10 > 1 && n % 10 < 5) {
        printf("ГОДА");
    } else {
        printf("ЛЕТ");
    }
    
    return 0;
}

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
    printf("��� %d ", n);
    if (n % 10 == 1 && n != 11) {
        printf("���");
    } else if (n % 10 > 1 && n % 10 < 5 && n < 10 && n > 14) {
        printf("����");
    } else {
        printf("���");
    }
    
    return 0;
}

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
    printf("ÂÀÌ %d ", n);
    if (n % 10 == 1) {
        printf("ÃÎÄ");
    } else if (n % 10 > 1 && n % 10 < 5) {
        printf("ÃÎÄÀ");
    } else {
        printf("ËÅÒ");
    }
    
    return 0;
}
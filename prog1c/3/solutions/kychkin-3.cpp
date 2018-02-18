#include<stdio.h>
#include<locale.h>
#include<math.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x >= 1 && x <= 100) {
        if (x >= 5 && x <= 20 || x % 10 == 5 || x % 10 == 6 || x % 10 == 7 || x % 10 == 8 || x % 10 == 9 || x % 10 == 0) {
            printf("ÂÀÌ %d ËÅÒ", x);
            } else {
                if (x % 10 == 1) {
                    printf("ÂÀÌ %d ÃÎÄ", x);
                    }
            else {
                printf("ÂÀÌ %d ÃÎÄÀ", x);
            }

        }

    } else {
        printf("ERROR");
        }
return 0;
}

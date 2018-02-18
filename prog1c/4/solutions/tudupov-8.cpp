#include <stdio.h>

int main() {
    float a1, b1, c1, a2, b2, c2;
    scanf("%f %f %f %f %f %f", &a1, &b1, &c1, &a2, &b2, &c2);
    if ((b1 == 0 && a1 == 0) || (b2 == 0 && a2 == 0)) {
        printf("ERROR");
    }
    else if (a1*b2-a2*b1 == 0 && b1*c2-b2*c1 == 0 ){
        printf("SAME");
    }
    } else if (a1*b2-a2*b1 == 0){
        printf("PARALLEL");
    } else {
        float x = (b2*c1-b1*c2)/(a2*b1-a1*b2);
        float y = (a1*c2-a2*c1)/(a2*b1-a1*b2);
        printf("%f %f", x, y);
    }
    return 0;
}
// Найти точку пересечения двух прямых, заданных с помощью нормального
// уравнения прямой

#include <cstdio>

int main () {
    float a1, b1, c1, a2, b2, c2;
    scanf("%f %f %f %f %f %f", &a1, &b1, &c1, &a2, &b2, &c2);
    if ( (b1 == 0 && a1 == 0) || (b2 == 0 && a2 == 0) ) {
        printf("ERROR");
        return 0;
    }
    if (a1*b2-a2*b1 == 0 && c1*b2-c2*b1 == 0){
        printf("SAME");
    } else if (a1*b2-a2*b1 == 0){
        printf("PARALLEL");
    } else {
        float x = (c2*b1-c1*b2)/(a1*b2-a2*b1);
        float y = (a2*c1-a1*c2)/(a1*b2-a2*b1);
        printf("%f %f", x, y);
    }
    return 0;
}
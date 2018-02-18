#include<stdio.h>
#include<locale.h>
#include<math.h>

int main () {
    int x;
    scanf ("%d", &x);
    if (x<0 || x>10) {
        printf ("ERROR");
    }
    if (x == 0) {
        printf ("ZERO");
    }
    if (x == 1) {
        printf ("one");
    }
    if (x == 2) {
        printf ("TWO");
    }
    if (x == 3) {
        printf ("THREE");
    }
    if (x == 4) {
        printf ("FOUR");
    }
    if (x == 5) {
        printf ("FIVE");
    }
    if (x == 6) {
        printf ("SIX");
    }
    if (x == 7) {
        printf ("SEVEN");
    }
    if (x == 8) {
        printf ("EIGHT");
    }
    if (x == 9) {
        printf ("NINE");
    }
}
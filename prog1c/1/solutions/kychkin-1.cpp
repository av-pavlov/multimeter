#include<stdio.h>
#include<locale.h>
#include<math.h>

int main () {
    int x;
    scanf ("%d", &x);
    
    if (x >=1 && x<=2200) {
        if (x % 400 == 0 || x % 4 == 0 && x % 100!=0) {
            printf ("LEAP");
        } else {
            printf ("NORMAL");
        }
    } else {
        printf ("ERROR");
    }
}
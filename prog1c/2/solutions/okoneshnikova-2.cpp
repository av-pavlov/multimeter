#include <stdio.h>

int main() {
    char ch;
    scanf ("%c" , &ch);
    if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) {
        if (ch>='A' && ch<='Z') {
            printf ("CAPITAL \n");
        }
        else {
            printf("LOWERCASE \n");
        }
    } else {
        if (ch>='0' && ch<='9') {
            printf("DIGIT \n");
        } else {
            printf("NON-ALPHANUMERIC \n");
        }
    }
    return 0;
}
// Символ

#include <cstdio>

int main () {
    char chr;
    scanf("%c", &chr);
    if (chr > 47 && chr < 58) {
        printf("DIGIT");
    } else if (chr > 64 && chr < 91) {
        printf("CAPITAL");
    } else if (chr > 96 && chr < 123) {
        printf("LOWERCASE");
    } else {
        printf("NON-ALPHANUMERIC");
    }
    
    return 0;
}
#include "stdio.h"
#include "math.h"

int main() {
    int year = 0;
    scanf("%d", &year);
    if (year >= 1 && year <= 2200) 
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
        {
            printf("LEAP");   
        }
        else
        {
            printf("NORMAL");
        }
    }
    else 
    {
        printf("ERROR");
    }
}
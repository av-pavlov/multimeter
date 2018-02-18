#include <stdio.h>

int main()
{
    int y = 0;
    
    scanf("%i", &y);
    if ((y >= 1) && (y <= 100))
    {
        printf("Р’РђРњ %i ", y);
        if (((y%100)/10 == 1) || !(y%10) || (y%10 > 4))
            printf("Р›Р•Рў");
        else
            if (y%10 == 1)
                printf("Р“РћР”");
            else
                printf("Р“РћР”Рђ");
        printf("\n\r");
    }
    else
        printf("ERROR\n\r");
    
    return 0;
}
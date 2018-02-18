#include <stdio.h>

int main()
{
	int y = 0;

	scanf("%i", &y);
	if ((y >= 1) && (y <= 100))
	{
    	printf("ВАМ %i ", y);
	    if (((y%100)/10 == 1) || !(y%10) || (y%10 > 4))
	        printf("ЛЕТ");
	    else
	        if (y%10 == 1)
	            printf("ГОД");
	        else
	            printf("ГОДА");
	    printf("\n\r");
	}
	else
	    printf("ERROR\n\r");

	return 0;
}

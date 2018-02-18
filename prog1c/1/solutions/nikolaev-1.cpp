#include <stdio.h>   

int main()
{
	int year = 0;

	scanf("%i", &year);
	if ((year < 1) || (year > 2200))
		printf("ERROR");
	else
		if ((year % 4) || (!(year % 100) && (year % 400)))
			printf("NORMAL");
		else
			printf("LEAP");

	return 0;
}

#include <stdio.h>

int main(){
	int year;
	scanf("%d", &year);

	if (year%4 == 0)
		printf("LEAP\n");
	else
		printf("NORMAL\n");

	return 0;
}
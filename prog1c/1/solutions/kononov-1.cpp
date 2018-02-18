#include<stdio.h>

int main() {
	int year;
	scanf("%d", &year);
	if (year < 1 || year > 2200) {
		printf("ERROR");
	}
	else {
		if (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0))) {
			printf("LEAP");
		}
		else printf("NORMAL");
	}
}
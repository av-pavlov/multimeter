#include<stdio.h>

int main() {
	int year;
	scanf("%d", &year);
	if (year>0 && year<101) {
		if (((year % 10)>4 && (year % 10) <= 9) || !(year % 10) || (year>10) && (year<15)) {
			printf("ÂÀÌ %d ËÅÒ", year);

		}
		else {
			if ((year % 10)>1 && (year % 10)<5) {
				printf("ÂÀÌ %d ÃÎÄÀ", year);
			}
			else {
				if ((year % 10) == 1) {
					printf("ÂÀÌ %d ÃÎÄ", year);

				}
			}
		}
	}
	else printf("ERROR");
}
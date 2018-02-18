#include "stdio.h"

int main(){
		int year;
		scanf("%d", &year);
		if (year >= 1 && year <= 100) {
			if (year >= 5 && year <= 20 || year % 10 == 5 || year % 10 == 6 || year % 10 == 7 || year % 10 == 8 || year % 10 == 9 || year % 10 == 0) {
				printf("ÂÀÌ %d ËÅÒ", year);
			}
			else {
				if (year % 10 == 1) {
					printf("ÂÀÌ %d ÃÎÄ", year);
				}
				else {
					printf("ÂÀÌ %d ÃÎÄÀ", year);
				}

			}
			
		}
		else {
			printf("ERROR");
		}
		return 0;
	}

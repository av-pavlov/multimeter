#include "stdio.h"

int main(){
		int year;
		scanf("%d", &year);
		if (year >= 1 && year <= 100) {
			if (year >= 5 && year <= 20 || year % 10 == 5 || year % 10 == 6 || year % 10 == 7 || year % 10 == 8 || year % 10 == 9 || year % 10 == 0) {
				printf("��� %d ���", year);
			}
			else {
				if (year % 10 == 1) {
					printf("��� %d ���", year);
				}
				else {
					printf("��� %d ����", year);
				}

			}
			
		}
		else {
			printf("ERROR");
		}
		return 0;
	}

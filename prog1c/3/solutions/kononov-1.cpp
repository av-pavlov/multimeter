#include<stdio.h>

int main() {
	int year;
	scanf("%d", &year);
	if (year>0 && year<101) {
		if (((year % 10)>4 && (year % 10) <= 9) || !(year % 10) || (year>10) && (year<15)) {
			printf("��� %d ���", year);

		}
		else {
			if ((year % 10)>1 && (year % 10)<5) {
				printf("��� %d ����", year);
			}
			else {
				if ((year % 10) == 1) {
					printf("��� %d ���", year);

				}
			}
		}
	}
	else printf("ERROR");
}
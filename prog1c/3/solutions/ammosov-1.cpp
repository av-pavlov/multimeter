#include <stdio.h>

int main(){
		int age;
		scanf("%d", &age);
		if (age >= 1 && age <= 100) {
			if (age >= 5 && age <= 20 || age % 10 == 5 || age % 10 == 6 || age % 10 == 7 || age % 10 == 8 || age % 10 == 9 || age % 10 == 0) 
				printf ("ВАМ %d ЛЕТ", age);
			 else {
				if (age % 10 == 1) {
					printf("ВАМ %d ГОД ", age);
				} else 
					printf("ВАМ %d ГОДА", age);

		}
			
		} else 
			printf("ERROR");
		
		return 0;
	}
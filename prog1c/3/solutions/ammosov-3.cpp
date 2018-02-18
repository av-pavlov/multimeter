//Напишите программу, которая вводит с клавиатуры возраст n лет и выводит сообщение ВАМ n ЛЕТ/ГОДА/ГОД, используя правильное слово,если 1⩽ n ⩽ 100, или ERROR в противном случае.

#include <locale.h>
#include <stdio.h>

int main(){
		int age;
		setlocale(LC_ALL, "");
		scanf("%d", &age);
		if (age >= 1 && age <= 100) {
			if (age >= 5 && age <= 20 || age % 10 == 5 || age % 10 == 6 || age % 10 == 7 || age % 10 == 8 || age % 10 == 9 || age % 10 == 0) 
				printf ("ВАМ %d ЛЕТ", age);
			 else {
				if (age % 10 == 1) {
					printf("ВАМ %d ГОД", age);
				} else 
					printf("ВАМ %d ГОДА", age);

		}
			
		} else 
			printf("ERROR");
		
		return 0;
	}
//�������� ���������, ������� ������ � ���������� ������� n ��� � ������� ��������� ��� n ���/����/���, ��������� ���������� �����,���� 1? n ? 100, ��� ERROR � ��������� ������.

#include <stdio.h>
#include <locale.h>

int main(){
		int age;
		setlocale(LC_ALL, "ru");
		scanf("%d", &age);
		if (age >= 1 && age <= 100) {
			if (age >= 5 && age <= 20 || age % 10 == 5 || age % 10 == 6 || age % 10 == 7 || age % 10 == 8 || age % 10 == 9 || age % 10 == 0) 
				printf ("��� %d ���", age);
			 else {
				if (age % 10 == 1) {
					printf("��� %d ���", age);
				} else 
					printf("��� %d ����", age);

		}
			
		} else 
			printf("ERROR");
		
		return 0;
	}
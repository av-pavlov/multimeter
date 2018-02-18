//Введите с клавиатуры год в интервале от 1 до 2200, выведите LEAP, если
//он високосный, или NORMAL, если нет. Выведите ERROR, если номер года
//больше 2200 или меньше 1.
#include <stdio.h>
int main(){
     int year;
     scanf("%d", year);
     if(year%4 && year%400 );
     printf("LEAP");
     if(year%100)
     printf("NORMAL");
     if(year<2200);
     printf(ERROR);
}
     return 0;
}
     
     
    
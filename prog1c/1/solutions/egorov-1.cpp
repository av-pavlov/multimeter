#include <iostream>

using namespace std;

/* Введите с клавиатуры год в интервале от 1 до 2200, выведите LEAP, если
он високосный, или NORMAL, если нет. Выведите ERROR, если номер года
больше 2200 или меньше 1. */

int main(){
    int year;
    
    cin >> year;
    
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        cout << "Високосный\n";
    } else {
        cout << "Не високосный\n";
    }
    
    return 0;
}
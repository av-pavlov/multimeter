/*
Введите с клавиатуры год в интервале от 1 до 2200, выведите LEAP, если
он високосный, или NORMAL, если нет. Выведите ERROR, если номер года
больше 2200 или меньше 1.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    
    if (a > 0 && a < 2201)
    {
        if ((a % 4 == 0 && a%100 != 0) || (a % 400 == 0))
        {
            cout << "LEAP"; 
        }else{
            cout << "NORMAl";
        }
    }else{
        cout << "Error!";
    }
    return 0;
}
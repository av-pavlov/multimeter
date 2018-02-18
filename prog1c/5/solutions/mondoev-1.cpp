/*
Введите с клавиатуры число n и выведите английское название соот-
ветствующей цифры от 0 до 9, либо ERROR, если число меньше 0 или
больше 9. Массивы не использовать.
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 0 || n > 9)
    {
        cout << "ERROR";
    }
    else
    {
        switch(n)
        {
            case 0:
                cout << "zero";
                break;
            case 1:
                cout << "one";
                break;
            case 2:
                cout << "two";
                break;
            case 3:
                cout << "three";
                break;
            case 4:
                cout << "four";
                break;    
            case 5:
                cout << "five";
                break;    
            case 6:
                cout << "six";
                break;    
            case 7:
                cout << "seven";
                break;    
            case 8:
                cout << "eight";
                break;    
            case 9:
                cout << "nine";
                break;    
        }
    }
}


 /* if (n == 0)
        {
            cout << "zero";
        }
        if (n == 1)
        {
            cout << "one";
        }
        if (n == 2)
        {
            cout << "two";
        }
        if (n == 3)
        {
            cout << "three";
        }
        if (n == 4)
        {
            cout << "four";
        }
        if (n == 5)
        {
            cout << "five";
        }
        if (n == 6)
        {
            cout << "six";
        }
        if (n == 7)
        {
            cout << "seven";
        }
        if (n == 8)
        {
            cout << "eight";
        }
        if (n == 9)
        {
           cout << "nine";
        }
        */
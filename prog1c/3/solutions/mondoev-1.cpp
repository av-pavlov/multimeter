/*
Напишите программу, которая вводит с клавиатуры возраст n лет и вы-
водит сообщение ВАМ n ЛЕТ/ГОДА/ГОД, используя правильное слово,
если 1 ? n ? 100, или ERROR в противном случае.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if ((a >= 1) && (a <= 100))
    {
        cout << "ВАМ " << a << " ";
    
    
        if ((a <= 10) || (a >= 20))
        {
            if (a % 10 == 1)
            {
                cout << "ГОД";
            }else{
                if ((a % 10 > 1) && (a % 10 < 5))
                {
                    cout << "ГОДА";
                }else{
                    cout << "ЛЕТ";
                }
            }
        }else{
            cout << "ЛЕТ";
        }
        
        
        
        
        
    }else{
        cout << "ERROR";
    }
    return 0;
}
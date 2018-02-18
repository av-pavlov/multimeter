/*
Ќапишите программу, котора€ вводит с клавиатуры один символ, и
выводит DIGIT, этот символ €вл€етс€ цифрой, CAPITAL Ч если за-
главной латинской буквой, LOWERCASE Ч если строчной, и выводит
NON-ALPHANUMERIC в противном случае.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char a;
    cin >> a;
    
    if (a >= 48 && a <= 57)
    {
        cout << "DIGIT";
    }else{
        if (a >= 65 && a <= 90)
    {
        cout << "CAPITAL";
    }else{
        if (a >= 97 && a <= 122)
        {
            cout << "LOWERCASE";
        }else{
            cout << "NON-ALPHANUMERIC";
        }
    }
    }
}
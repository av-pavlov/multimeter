/*
������� � ���������� ��� � ��������� �� 1 �� 2200, �������� LEAP, ����
�� ����������, ��� NORMAL, ���� ���. �������� ERROR, ���� ����� ����
������ 2200 ��� ������ 1.
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
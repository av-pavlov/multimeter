/*
�������� ���������, ������� ������ � ���������� ������� n ��� � ��-
����� ��������� ��� n ���/����/���, ��������� ���������� �����,
���� 1 ? n ? 100, ��� ERROR � ��������� ������.
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
        cout << "��� " << a << " ";
    
    
        if ((a <= 10) || (a >= 20))
        {
            if (a % 10 == 1)
            {
                cout << "���";
            }else{
                if ((a % 10 > 1) && (a % 10 < 5))
                {
                    cout << "����";
                }else{
                    cout << "���";
                }
            }
        }else{
            cout << "���";
        }
        
        
        
        
        
    }else{
        cout << "ERROR";
    }
    return 0;
}
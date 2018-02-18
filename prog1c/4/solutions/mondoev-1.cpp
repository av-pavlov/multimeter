/*
������� � ���������� ������������ ����� a1, b1, c1, a2, b2,c2. ��������
����� ������ ���������� ����� ����������� ���� ������, ��������
����������� aix+biy+c = 0, ���� ������ ������������ � ���������-
��� �����, ��� ������� SAME, ���� ������ ���������, PARALLEL, ����
��� ����������� �� �� ���������, ��� ERROR, ���� ��������� ����� ��
������ ���� ������.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    float a1, a2, b1, b2, c1, c2, x, y;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0))
    {
        cout << "ERROR";
    }
    else
    {
        if (a1 / a2 == b1 / b2)
        {
            if ((a1 / a2 == b1 / b2) && (a1 / a2 == c1 / c2))
            {
                cout << "SAME";
            }
            else
            {
                cout << "PARALLEL";
            }
        }
        else
        {
        
            x=-1*(c1*b2-c2*b1)/(a1*b2-a2*b1);
            y=-1*(a1*c2-a2*c1)/(a1*b2-a2*b1);
    
            cout << x << " " << y;
        }
    }
    
    
}
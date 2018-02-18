#include <iostream>

using namespace std;

/* Напишите программу, которая вводит с клавиатуры возраст n лет и вы-
водит сообщение ВАМ n ЛЕТ/ГОДА/ГОД, используя правильное слово,
если 1 ⩽ n ⩽ 100, или ERROR в противном случае. */

int main() {
    int age, lastNum;
    
    cin >> age;
    
    lastNum = age % 10;
    
    if (age >= 1 && age <= 100) {
        if (lastNum > 0 && lastNum < 2  && (age > 11 || age == 1)) {
            cout << "��� " << age << " ���\n";
        } else if (lastNum > 1 && lastNum < 5 && (age > 14 || age < 5)) {
            cout << "��� " << age << " ����\n";
        } else {
            cout << "��� " << age << " ���\n";
        }
    } else {
        cout << "ERROR\n";
    }
    
    return 0;
}
#include "locale.h"
#include <iostream>

using namespace std;

int main() {
    int age, lastNum;
    
    cin >> age;
    
    lastNum = age % 10;
    
    if (age >= 1 && age <= 100) {
        if (lastNum > 0 && lastNum < 2  && (age > 11 || age == 1)) {
            cout << "ВАМ " << age << " ГОД"; 
        } else if (lastNum > 1 && lastNum < 5 && (age > 14 || age < 5)) {
            cout << "ВАМ " << age << " ГОДА"; 
        } else {
            cout << "ВАМ " << age << " ЛЕТ"; 
        }
    } else {
        cout << "ERROR\n";
    }
    
    return 0;
}
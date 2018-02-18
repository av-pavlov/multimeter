#include <iostream>

using namespace std;

/* Введите с клавиатуры число n и выведите английское название соот-
ветствующей цифры от 0 до 9, либо ERROR, если число меньше 0 или
больше 9. Массивы не использовать. */

int main() {
    int number;
    
    cin >> number;
    
    switch(number) {
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
        default:
            cout << "ERROR";
            break;
    }
    
    //cout << "\n";
    
    return 0;
}
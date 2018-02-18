#include <iostream>

using namespace std;

/* Напишите программу, которая вводит с клавиатуры один символ, и
выводит DIGIT, этот символ является цифрой, CAPITAL — если за-
главной латинской буквой, LOWERCASE — если строчной, и выводит
NON-ALPHANUMERIC в противном случае. */

int main() {
    char symbol;
    
    cin >> symbol;
    
    int scode = (int) symbol;
    
    if (scode > 47 && scode < 58) {
        cout << "DIGIT\n";
    } else if (scode > 64 && scode < 91) {
        cout << "CAPITAL\n";
    } else if (scode > 96 && scode < 123) {
        cout << "LOWERCASE\n";
    } else {
        cout << "NON-ALPHANUMERIC\n";
    }
    
    return 0;
}
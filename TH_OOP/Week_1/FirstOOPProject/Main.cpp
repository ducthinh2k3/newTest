// File Main.cpp nằm Source File. Chứa hàm main
#include "Fraction.h"
#include <iostream>
using namespace std;

int main()
{
    Fraction a;
    int num1;
    int num2;
    cout << "Enter numerator: ";
    cin >> num1;
    cout << "Enter denominator: ";
    cin >> num2;
    a.setValue(num1, num2);
    a.printOnScreen();
}
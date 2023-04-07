// File Fraction.cpp nằm Source File. Dùng để cài đặt các
// phương thức đã báo ở Fraction.h

#include <iostream>
#include "Fraction.h"
using namespace std;

void Fraction::setValue(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::printOnScreen()
{
    cout << "Numerator is: " << numerator << endl;
    cout << "Denominator is: " << denominator << endl;
}
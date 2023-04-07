#include "Fraction.h"

Fraction::Fraction()
{
    tu = 0;
    mau = 1;
}

istream &operator>>(istream &in, Fraction &f)
{
    cout << "tu so: ";
    cin >> f.tu;

    do
    {
        cout << "mau so (Khac 0): ";
        cin >> f.mau;
    } while (f.mau == 0);
    return in;
}

ostream &operator<<(ostream &out, Fraction f)
{
    cout << f.tu << "/" << f.mau << endl;
    return out;
}

Fraction::~Fraction()
{
    tu = 0;
    mau = 1;
}
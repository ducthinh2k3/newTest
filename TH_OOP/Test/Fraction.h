#include <iostream>
using namespace std;

class Fraction
{
private:
    int tu, mau;

public:
    Fraction();
    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& out, Fraction f);
    ~Fraction();
};

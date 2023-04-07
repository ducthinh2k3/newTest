#include <iostream>
using namespace std;

class Fraction
{
private:
    int tu, mau;

public:
    Fraction();
    Fraction(int tu, int mau);
    Fraction(const Fraction &f);
    bool isValid(Fraction f); // kiểm tra phân số f có hợp lệ không
    Fraction &operator=(const Fraction &f);
    Fraction operator+(const Fraction &f);
    Fraction operator-(const Fraction &f);
    Fraction operator*(const Fraction &f);
    Fraction operator/(const Fraction &f);

    bool operator==(const Fraction &f);
    bool operator!=(const Fraction &f);
    bool operator>=(const Fraction &f);
    bool operator>(const Fraction &f);
    bool operator<=(const Fraction &f);
    bool operator<(const Fraction &f);

    Fraction operator+(int number);
    Fraction operator-(int number);
    friend Fraction operator+(int number, Fraction const &f);
    friend Fraction operator*(int number, Fraction const &f);

    Fraction &operator+=(const Fraction &f);
    Fraction &operator-=(const Fraction &f);
    Fraction &operator*=(const Fraction &f);
    Fraction &operator/=(const Fraction &f);

    Fraction operator++(int x); // a++
    Fraction &operator++();     //++a
    Fraction operator--(int x);
    Fraction &operator--();

    operator int() const;
    operator float() const;

    friend ostream &operator<<(ostream &out, Fraction f);
};

bool Fraction::isValid(Fraction f)
{
    if (f.mau == 0)
        return false;
    return true;
}

Fraction::Fraction()
{
    tu = 0;
    mau = 1;
}

Fraction::Fraction(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}

Fraction::Fraction(const Fraction &f)
{
    this->tu = f.tu;
    this->mau = f.mau;
}

Fraction &Fraction::operator=(const Fraction &f)
{
    if (isValid(f))
    {
        this->tu = f.tu;
        this->mau = f.mau;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction &f)
{
    Fraction result;
    result.tu = this->tu * f.mau + this->mau * f.tu;
    result.mau = this->mau * f.mau;
    return result;
}

Fraction Fraction::operator-(const Fraction &f)
{
    Fraction result;
    result.tu = this->tu * f.mau - this->mau * f.tu;
    result.mau = this->mau * f.mau;
    return result;
}

Fraction Fraction::operator*(const Fraction &f)
{
    Fraction result;
    result.tu = this->tu * f.tu;
    result.mau = this->mau * f.mau;
    return result;
}

Fraction Fraction::operator/(const Fraction &f)
{
    Fraction result;
    if (f.tu == 0)
    {
        cout << "Cannot divide by zero!" << endl;
        result.mau = 0;
        return result;
    }
    result.tu = this->tu * f.mau;
    result.mau = this->mau * f.tu;
    return result;
}

bool Fraction::operator==(const Fraction &f)
{
    int d = tu * f.mau - mau * f.tu;
    if (d == 0)
        return true;
    return false;
}

bool Fraction::operator!=(const Fraction &f)
{
    int d = tu * f.mau - mau * f.tu;
    if (d == 0)
        return false;
    return true;
}

bool Fraction::operator>=(const Fraction &f)
{
    int d = tu * f.mau - mau * f.tu;
    if (d >= 0)
        return true;
    return false;
}

bool Fraction::operator>(const Fraction &f)
{
    int d = tu * f.mau - mau * f.tu;
    if (d > 0)
        return true;
    return false;
}

bool Fraction::operator<=(const Fraction &f)
{
    int d = tu * f.mau - mau * f.tu;
    if (d <= 0)
        return true;
    return false;
}

bool Fraction::operator<(const Fraction &f)
{
    int d = tu * f.mau - mau * f.tu;
    if (d < 0)
        return true;
    return false;
}

Fraction Fraction::operator+(int number)
{
    Fraction result;
    result.tu = (this->tu + number * this->mau)*-1;
    result.mau = (this->mau)*-1     ;
    return result;
}

Fraction Fraction::operator-(int number)
{
    Fraction result;
    result.tu = (this->tu - number * this->mau)*-1;
    result.mau = (this->mau)*-1;
    return result;
}

Fraction operator+(int number, const Fraction &f)
{
    Fraction result;
    result.tu = (f.tu + number * f.mau)*-1;
    result.mau = (f.mau)*-1;
    return result;
}

Fraction operator*(int number, const Fraction &f)
{
    Fraction result;
    result.tu = (f.tu * number)*-1;
    result.mau = f.mau * -1;
    return result;
}

Fraction &Fraction::operator+=(const Fraction &f)
{
    this->tu = (this->tu * f.mau + this->mau * f.tu);
    this->mau = (this->mau * f.mau);
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &f)
{
    this->tu = this->tu * f.mau - this->mau * f.tu;
    this->mau = this->mau * f.mau;
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &f)
{
    this->tu = this->tu * f.tu;
    this->mau = this->mau * f.mau;
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &f)
{
    if (f.tu != 0)
    {
        this->tu = this->tu * f.mau;
        this->mau = this->mau * f.tu;
    }
    else
    {
        cout << "Cannot divide by zero!" << endl;
    }
    return *this;
}

Fraction Fraction::operator++(int x)
{
    Fraction d(*this);
    tu = tu + mau;
    return d;
}

Fraction &Fraction::operator++()
{
    tu = tu + mau;
    return *this;
}

Fraction Fraction::operator--(int x)
{
    Fraction d(*this);
    tu = tu - mau;
    return d;
}

Fraction &Fraction::operator--()
{
    tu = tu - mau;
    return *this;
}

Fraction::operator int() const
{
    return this->tu / this->mau;
}

Fraction::operator float() const
{
    return (double)this->tu / this->mau;
}

ostream &operator<<(ostream &out, Fraction f)
{
    int temp = f.tu / f.mau;
    if(f.mau* temp == f.tu)
    {
        cout << temp;
        return out;
    }
    else
    {
    out << f.tu << "/" << f.mau;
    }
    return out;
}

int main()
{
    Fraction f1, f2;     // 0/1
    Fraction f3(1, -7);  // -1/7
    Fraction f4(f3);     // Copy constructor
    Fraction f5 = f2;    // Copy constructor
    Fraction f6, f7, f8; // Default constructor
    f6 = f3;             // Operator =
    f7 = f1 + f5;
    f8 = f2 - f4;
    f3 = f1 * f7;
    f5 = f6 / f2; // Cannot divide by zero!
    if (f2 == f3)
        cout << "f2==f3" << endl;
    if (f3 != f1)
        cout << "f3!=f1" << endl;
    if (f2 >= f5)
        cout << "f2>=f5" << endl;
    if (f2 > f5)
        cout << "f2>f5" << endl;
    if (f5 <= f3)
        cout << "f5<=f3" << endl;
    if (f5 < f3)
        cout << "f5<f3" << endl;
    f1 = f2 + 3;
    f3 = -7 + f1;
    f5 = 7 * f3;
    f6 = f4 - 6;
    cout << f3 << endl;
    cout << f6 << endl;
    f1 += f5;
    f6 -= f7;
    f8 *= f1;
    f8 /= f2; // Cannot divide by zero!
    cout << f8++ << endl;
    cout << ++f7 << endl;
    cout << f8-- << endl;
    cout << --f7 << endl;
    f3 += Fraction(11, 2);
    int x = int(f3);     // 3/2 => 1
    float f = (float)f3; // 3/2 => 1.5
    cout << x << endl;
    cout << f << endl;
}
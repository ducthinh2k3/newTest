#include <iostream>
using namespace std;

class Fraction
{
private:
    int *numerator;
    int *denomirator;

public:
    Fraction();
    Fraction(const int x, const int y);
    Fraction(const Fraction &ps);
    ~Fraction();
    Fraction &operator=(const Fraction &ps);
    Fraction operator+(const int x);
    Fraction operator+(const Fraction &ps);
    Fraction &operator+=(const Fraction &ps);
    bool operator==(const Fraction &ps);
    Fraction &operator++();
    Fraction operator++(int x);
    friend istream &operator>>(istream &in, Fraction &ps);
    friend ostream &operator<<(ostream &out, Fraction ps);
};

Fraction::Fraction()
{
    numerator = new int;
    denomirator = new int;
}

Fraction::Fraction(const int x, const int y)
{
    numerator = new int;
    *numerator = x;
    denomirator = new int;
    *denomirator = y;
}

Fraction::Fraction(const Fraction &ps)
{
    numerator = new int;
    denomirator = new int;
    *numerator = *ps.numerator;
    *denomirator = *ps.denomirator;
}

Fraction::~Fraction()
{
    delete numerator;
    delete denomirator;
}

Fraction &Fraction::operator=(const Fraction &ps)
{
    // con trỏ this trỏ đến vùng nhớ lưu chủ nhân hàm này
    if (this == &ps)
        return *this;

    delete numerator;
    delete denomirator;
    numerator = new int;
    denomirator = new int;
    *numerator = *ps.numerator;
    *denomirator = *ps.denomirator;
    return *this;
}

Fraction Fraction::operator+(const int x)
{
    Fraction res;
    *res.numerator = *this->numerator + x * (*this->denomirator);
    *res.denomirator = *this->denomirator;
    return res;

    // C2 error
    // Fraction res(x, 1);
    // return *this + res;
}

Fraction &Fraction::operator+=(const Fraction &ps)
{
    *this->numerator = *this->numerator * (*ps.denomirator) + *ps.numerator * (*this->denomirator);
    *this->denomirator = *this->denomirator * (*ps.denomirator);
    return *this;
}

bool Fraction::operator==(const Fraction &ps)
{
    int res = *this->numerator * (*ps.denomirator) - *ps.numerator * (*this->denomirator);
    if (res == 0)
        return true;
    return false;
}

//++a
Fraction &Fraction::operator++()
{
    *this->numerator = *this->numerator + *this->denomirator;
    return *this;
}

//++a
Fraction Fraction::operator++(int x)
{
    Fraction temp(*this);
    *this->numerator = *this->numerator + *this->denomirator;
    return temp;
}

istream &operator>>(istream &in, Fraction &ps)
{
    cout << "Nhap tu so: ";
    in >> *ps.numerator;
    cout << "Nhap mau so: ";
    in >> *ps.denomirator;
    return in;
}

ostream &operator<<(ostream &out, Fraction ps)
{
    out << *ps.numerator << "/" << *ps.denomirator << endl;
    return out;
}

int main()
{
    Fraction a(1, 3);
    // cin >> a;
    // cout << a;

    Fraction b(2,4);
    Fraction c;
    c = a + 1;
    cout << a;
    cout << c;
    cout << (a == a) << endl;

    b=a+1;
    cout << b << endl;
}
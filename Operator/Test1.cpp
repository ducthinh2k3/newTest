#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo &operator=(const PhanSo &p);
    PhanSo operator+(const PhanSo &p);
    PhanSo &operator+=(const PhanSo &p);
    friend istream &operator>>(istream &in, PhanSo &p);
    friend ostream &operator<<(ostream &out, PhanSo p);
    PhanSo operator++(int x);
    PhanSo& operator++();
    PhanSo(int a, int b)
    {
        this->tu = a;
        this->mau = b;
    };
};

istream &operator>>(istream &in, PhanSo &p)
{
    in >> p.tu >> p.mau;
    return in;
}

ostream &operator<<(ostream &out, PhanSo p)
{
    out << p.tu << "/" << p.mau << endl;
    return out;
}

PhanSo &PhanSo::operator+=(const PhanSo &p)
{
    this->tu = this->tu * p.mau + this->mau * p.tu;
    this->mau = this->mau * p.mau;
    return *this;
}

PhanSo &PhanSo::operator=(const PhanSo &p)
{
    if (this == &p)
        return *this;
    cout << "Da thuc hien" << endl;
    this->tu = p.tu;
    this->mau = p.mau;
    return *this;
}

PhanSo PhanSo::operator+(const PhanSo &p)
{
    PhanSo kq(0, 1);
    kq.tu = this->tu * p.mau + this->mau * p.tu;
    kq.mau = this->mau * p.mau;
    return kq;
}

PhanSo PhanSo::operator++(int x)
{
    PhanSo d(0, 1);
    d.tu = tu;
    d.mau = mau;
    tu = tu + mau;
    return d;
}

PhanSo& PhanSo::operator++()
{
    tu = tu + mau;
    return *this;
}

int main()
{
    PhanSo a(1, 2);
    PhanSo b(1, 3);
    b=a++;
    cout << b << endl << a;
}
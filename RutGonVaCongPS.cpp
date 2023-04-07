#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo(int, int);
    friend istream &operator>>(istream &in, PhanSo &p);
    friend ostream &operator<<(ostream &out, PhanSo p);
    PhanSo operator+(PhanSo q);
    void rutgon();
};

PhanSo::PhanSo(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}

istream &operator>>(istream &in, PhanSo &p)
{
    in >> p.tu;
    do
    {
        in >> p.mau;
    } while (p.mau == 0);
    return in;
}

ostream &operator<<(ostream &out, PhanSo p)
{
    out << p.tu << "/" << p.mau;
    return out;
}

// int tichBoiChung(int a, int b)
// {
//     int sum = 1;
//     for (int i = 1; i <= a; i++)
//     {
//         if (a % i == 0 && b % i == 0)
//             sum = sum * i;
//     }
//     return sum;
// } Saiii

int ucln(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return ucln(a - b, b);
    if (b > a)
        return ucln(a, b - a);
}

PhanSo PhanSo::operator+(PhanSo q)
{
    PhanSo tong(1, 1);
    int bcnn = (this->mau * q.mau) / ucln(this->mau, q.mau);
    tong.mau = bcnn;
    tong.tu = this->tu * (bcnn / this->mau) + q.tu * (bcnn / q.mau);
    tong.rutgon();
    return tong;
}

void PhanSo::rutgon()
{
    int u = ucln(tu, mau);
    tu = tu / u;
    mau = mau / u;
}

int main()
{
    PhanSo p(1, 1), q(1, 1);
    cin >> p >> q;
    cout << p + q;
    return 0;
}
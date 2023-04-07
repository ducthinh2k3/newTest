#include <iostream>
using namespace std;
class PhanSo
{
private:
    int tu, mau;

public:
    void xuat();
    void init(int t, int m);
    PhanSo(int t, int m);
    PhanSo(int x);
    PhanSo();
    PhanSo(const PhanSo &other);
    PhanSo cong(PhanSo &b);
    ~PhanSo();
};

PhanSo::~PhanSo()
{
    cout << "destructor" << endl;
}

void PhanSo::xuat()
{
    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    }
    cout << tu << "/" << mau;
}

void PhanSo::init(int t, int m)
{
    if (m == 0)
        m = 1;
    tu = t;
    mau = m;
}

PhanSo::PhanSo(int t, int m)
{
    cout << "2-param cons" << endl;
    if (m == 0)
        m = 1;
    tu = t;
    mau = m;
}

PhanSo::PhanSo(int x)
{
    cout << "1-param cons" << endl;
    tu = x;
    mau = 1;
}

PhanSo::PhanSo()
{
    cout << "default cons" << endl;
    tu = 0;
    mau = 1;
}

PhanSo::PhanSo(const PhanSo &other)
{
    cout << "copy cons" << endl;
    tu = other.tu;
    mau = other.mau;
}

PhanSo PhanSo::cong(PhanSo &b)
{
    cout << "cong 2 ps" << endl;
    PhanSo kq;
    kq.tu = tu * b.mau + mau * b.tu;
    kq.mau = mau * b.mau;
    return kq;
}

int main()
{
    PhanSo p1(1, 2);
    PhanSo p2(3, 4);
    PhanSo p3 = p1.cong(p2); // PhanSo p3 = PhanSo(px), PhanSo p3 = px, p2 truyền tham chiếu nên k xây dụng copy cons
    p3.xuat();
    cout << endl;
    return 0;
}
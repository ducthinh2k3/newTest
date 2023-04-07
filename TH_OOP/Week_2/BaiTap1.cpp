#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo();
    ~PhanSo();
    void Nhap();
    PhanSo congPhanSo(PhanSo p);
    PhanSo truPhanSo(PhanSo p);
    PhanSo nhanPhanSo(PhanSo p);
    PhanSo chiaPhanSo(PhanSo p);
    void Xuat1(); // Xuất theo định dạng tử số / mẫu số
    void Xuat2(); // Xuất theo định dạng kết quả phép chia của tử số và mẫu số (số thập phân)
};

PhanSo::PhanSo()
{
    tu = mau = 1;
}

PhanSo::~PhanSo()
{
    tu = mau = 1;
}

void PhanSo::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> tu;

    do
    {
        cout << "Nhap mau so (Khac 0): ";
        cin >> mau;
    } while (mau == 0);
}

void PhanSo::Xuat1()
{
    cout << "Phan so: " << tu << "/" << mau << endl;
}

void PhanSo::Xuat2()
{
    cout << "Phan so (dang thap phan): " << (double)tu / mau << endl;
}

PhanSo PhanSo::congPhanSo(PhanSo p)
{
    PhanSo result;
    result.tu = this->tu * p.mau + this->mau * p.tu;
    result.mau = this->mau * p.mau;
    return result;
}

PhanSo PhanSo::truPhanSo(PhanSo p)
{
    PhanSo result;
    result.tu = this->tu * p.mau - this->mau * p.tu;
    result.mau = this->mau * p.mau;
    return result;
}

PhanSo PhanSo::nhanPhanSo(PhanSo p)
{
    PhanSo result;
    result.tu = this->tu * p.tu;
    result.mau = this->mau * p.mau;
    return result;
}

PhanSo PhanSo::chiaPhanSo(PhanSo p)
{
    PhanSo result;
    if(p.tu == 0)
    {
        cout << "Khong chia duoc" << endl;
        return result;
    }
    result.tu = this->tu * p.mau;
    result.mau = this->mau * p.tu;
    return result;
}

int main()
{
    PhanSo p;
    PhanSo q;
    PhanSo result;
    cout << "---Nhap phan so---" << endl; 
    p.Nhap();
    cout << "---Nhap phan so---" << endl; 
    q.Nhap();
    cout << "Ket qua cong phan so" << endl;
    result = p.congPhanSo(q);
    result.Xuat1();
    result.Xuat2();

    cout << "Ket qua tru phan so" << endl;
    result = p.truPhanSo(q);
    result.Xuat1();
    result.Xuat2();

    cout << "Ket qua nhan phan so" << endl;
    result = p.nhanPhanSo(q);
    result.Xuat1();
    result.Xuat2();

    cout << "Ket qua chia phan so" << endl;
    result = p.chiaPhanSo(q);
    result.Xuat1();
    result.Xuat2();
}


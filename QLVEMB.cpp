#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
private:
    int ngay, thang, nam;

public:
    Date();
    ~Date();
    void Nhap();
    void Xuat();
};

void Date::Nhap()
{
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
}

void Date::Xuat()
{
    cout << "Ngay/Thang/Nam: " << ngay << "/" << thang << "/" << nam << endl;
}

Date::Date()
{
    ngay = thang = nam = 1;
}

Date::~Date()
{
    ngay = thang = nam = 1;
}

class Vemaybay
{
private:
    Date ngayBay;
    string tenChuyen;
    double giaVe;

public:
    Vemaybay();
    ~Vemaybay();
    void Nhap();
    void Xuat();
    double getGiaVe();
};

Vemaybay::Vemaybay()
{
    tenChuyen = "";
    giaVe = 0;
}

Vemaybay::~Vemaybay()
{
    tenChuyen = "";
    giaVe = 0;
}

void Vemaybay::Nhap()
{
    cout << "Nhap ten chuyen: ";
    getline(cin, tenChuyen);
    ngayBay.Nhap();
    cout << "Nhap gia ve: ";
    cin >> giaVe;
    cin.ignore();
}

void Vemaybay::Xuat()
{
    cout << "Ten chuyen: " << tenChuyen << endl;
    cout << "Ngay bay: ";
    ngayBay.Xuat();
    cout << "Gia ve: " << giaVe << endl;
}

double Vemaybay::getGiaVe()
{
    return giaVe;
}

class Nguoi
{
private:
    string hoTen, gioiTinh;
    unsigned int tuoi;

public:
    Nguoi();
    ~Nguoi();
    void Nhap();
    void Xuat();
};

Nguoi::Nguoi()
{
    hoTen = gioiTinh = "";
    tuoi = 0;
}

Nguoi::~Nguoi()
{
    hoTen = gioiTinh = "";
    tuoi = 0;
}

void Nguoi::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore();
}

void Nguoi::Xuat()
{
    cout << "Ho ten:" << hoTen << endl;
    cout << "Gioi tinh: " << gioiTinh << endl;
    cout << "Tuoi: " << tuoi << endl;
}

class HanhKhach : public Nguoi
{
private:
    Vemaybay *ve;
    int soLuong;

public:
    HanhKhach();
    ~HanhKhach();
    void Nhap();
    void Xuat();
    double tongTien();
};

HanhKhach::HanhKhach()
{
    ve = NULL;
    soLuong = 0;
}

HanhKhach::~HanhKhach()
{
    delete ve;
    ve = NULL;
    soLuong = 0;
}

void HanhKhach::Nhap()
{
    Nguoi::Nhap();
    cout << "Nhap so luong ve: ";
    cin >> soLuong;
    cin.ignore();
    ve = new Vemaybay[soLuong];
    for (int i = 0; i < soLuong; i++)
    {
        cout << endl;
        cout << "Nhap ve may bay " << i + 1 << ": " << endl;
        ve[i].Nhap();
    }
}

void HanhKhach::Xuat()
{
    Nguoi::Xuat();
    for (int i = 0; i < soLuong; i++)
    {
        cout << endl;
        cout << "Thong tin ve may bay " << i + 1 << ": " << endl;
        ve[i].Xuat();
    }
}

double HanhKhach::tongTien()
{
    double result = 0;
    for (int i = 0; i < soLuong; i++)
    {
        result = ve[i].getGiaVe() + result;
    }
    return result;
}

int main()
{
    int number;
    cout << "Nhap so luong hanh khach: ";
    cin >> number;
    cin.ignore();
    HanhKhach* h = new HanhKhach[number];
    for(int i=0;i < number; i++)
    {
        cout << "--------Hanh khach thu " << i+1 << "-------------" << endl;
        h[i].Nhap();
    }
    
    for(int i=0; i<number; i++)
    {
        cout << "--------Hanh khach thu " << i+1 << "-------------" << endl;
        h[i].Xuat();
        cout << "So tien phai tra: " << h[i].tongTien() << endl;
    }
}

#include <iostream>
#include <string>
using namespace std;

class Xe
{
private:
    string ho_ten;
    float so_gio;

public:
    string getTen()
    {
        return ho_ten;
    };
    float getGio()
    {
        return so_gio;
    };
    void setTen()
    {
        cout << "Ho ten: ";
        getline(cin, ho_ten);
    };
    void setGio()
    {
        cout << "Gio: ";
        cin >> so_gio;
        cin.ignore();
    }
};

class XeDap : public Xe
{
public:
    void input();
    void output();
    float tien_thue_xe_dap();
};

class XeMay : public Xe
{
private:
    string bien_so;
    int loai_xe;

public:
    float tien_thue_xe_may();
    void input();
    void output();
};

float XeMay::tien_thue_xe_may()
{
    float tien = 0;
    if (getGio() <= 1)
    {
        if (loai_xe == 100)
            tien = getGio() * 150000;
        else
            tien = getGio() * 200000;
    }
    else
    {
        if (loai_xe == 100)
            tien = 150000;
        else
            tien = 200000;
        tien = (getGio() - 1) * 100000 + tien;
    }
    return tien;
}

float XeDap::tien_thue_xe_dap()
{
    float tien = 0;
    if (getGio() <= 1)
        tien = getGio() * 10000;
    else
    {
        tien = 10000 + (getGio() - 1) * 8000;
    }
    return tien;
}

void XeDap::input()
{
    setTen();
    setGio();
}

void XeDap::output()
{
    cout << "Ho ten: " << getTen() << endl;
    cout << "Gio: " << getGio() << endl;
}

void XeMay::input()
{
    setTen();
    setGio();
    cout << "Bien so: ";
    getline(cin, bien_so);
    cout << "Loai xe: ";
    cin >> loai_xe;
    cin.ignore();
}

void XeMay::output()
{
    cout << "Ho ten: " << getTen() << endl;
    cout << "Gio: " << getGio() << endl;
    cout << "Bien so: " << bien_so << endl;
    cout << "Loai xe: " << loai_xe << endl;
}

void xuat_thong_tin(XeDap a[], XeMay b[], int n, int m)
{
    cout << "Xe dap" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].output();
        cout << "Tien thue: " << a[i].tien_thue_xe_dap() << endl;
    }
    cout << "Xe may" << endl;
    for (int i = 0; i < m; i++)
    {
        b[i].output();
        cout << "Tien thue: " << b[i].tien_thue_xe_may() << endl;
    }
}

float tinh_tong_tien_thue(XeDap a[], XeMay b[], int n, int m)
{
    float tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += a[i].tien_thue_xe_dap();
    }

    for (int i = 0; i < m; i++)
    {
        tong += b[i].tien_thue_xe_may();
    }
    return tong;
}

void Menu(XeDap a[], XeMay b[], int &n, int &m)
{
    n = m = 0;
    int lua_chon;

    cout << "------ Quan li Thue Xe ------" << endl;
    cout << "0: close" << endl;
    cout << "1: Thue xe dap" << endl;
    cout << "2: Thue xe may" << endl;
    cout << "3: Xuat tat ca thong tin thue xe" << endl;
    cout << "4: Tong tien thue" << endl;

    while (true)
    {
        do
        {
            cout << endl
                 << "Nhap lua chon: ";
            cin >> lua_chon;
            cin.ignore();
        } while (lua_chon < 0 || lua_chon > 3);

        switch (lua_chon)
        {
        case 0:
            return;
        case 1:
            a[n++].input();
            break;
        case 2:
            b[m++].input();
            break;
        case 3:
            xuat_thong_tin(a, b, n, m);
            break;
        case 4:
            cout << "Tong tien thue: " << tinh_tong_tien_thue(a, b, m, n);
            break;
        }
    }
}

int main()
{
    XeDap a[100];
    XeMay b[100];
    int n, m;
    Menu(a, b, n, m);
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Đọc giả
class DocGia
{
private:
    string ho_ten, ngay_lap;
    int so_thang;

public:
    virtual void input();
    virtual void output();
    virtual int tinh_tien_lam_the() = 0;
    int getThang();
    DocGia();
    ~DocGia();
};

void DocGia::input()
{
    cout << "Ho ten: ";
    getline(cin, ho_ten);
    cout << "Ngay lap the: ";
    getline(cin, ngay_lap);
    cout << "Hieu luc: ";
    cin >> so_thang;
    cin.ignore();
}

void DocGia::output()
{
    cout << "Ho ten: " << ho_ten << endl;
    cout << "Ngay lap the: " << ngay_lap << endl;
    cout << "Hieu luc: " << so_thang << endl;
}

int DocGia::getThang()
{
    return so_thang;
}

DocGia::DocGia()
{
}

DocGia::~DocGia()
{
}

// Đọc giả trẻ em
class DocGiaTreEm : public DocGia
{
private:
    string ho_ten_dd;

public:
    void input();
    void output();
    int tinh_tien_lam_the();
    DocGiaTreEm();
    ~DocGiaTreEm();
};

DocGiaTreEm::DocGiaTreEm()
{
}

DocGiaTreEm::~DocGiaTreEm()
{
}

void DocGiaTreEm::input()
{
    DocGia::input();
    cout << "Ho ten ndd: ";
    getline(cin, ho_ten_dd);
}

void DocGiaTreEm::output()
{
    DocGia::output();
    cout << "Ho ten ndd: " << ho_ten_dd << endl;
}

int DocGiaTreEm::tinh_tien_lam_the()
{
    return getThang() * 5000;
}

// Đọc giả người lớn
class DocGiaNguoiLon : public DocGia
{
private:
    string cmnd;

public:
    void input();
    void output();
    int tinh_tien_lam_the();
    DocGiaNguoiLon();
    ~DocGiaNguoiLon();
};

DocGiaNguoiLon::DocGiaNguoiLon()
{
}

DocGiaNguoiLon::~DocGiaNguoiLon()
{
}

void DocGiaNguoiLon::input()
{
    DocGia::input();
    cout << "Ho ten cmnd: ";
    getline(cin, cmnd);
}

void DocGiaNguoiLon::output()
{
    DocGia::output();
    cout << "Ho ten cmnd: " << cmnd << endl;
}

int DocGiaNguoiLon::tinh_tien_lam_the()
{
    return getThang() * 10000;
}

// thư viện
class ThuVien
{
private:
    vector<DocGia *> ds_docgia;

public:
    void input();
    void output();
    int tinh_tong_tien_lam_the();
    ThuVien();
    ~ThuVien();
};

ThuVien::ThuVien()
{
}

ThuVien::~ThuVien()
{
}

void ThuVien::input()
{
    int lua_chon;
    cout << "-------- QUAN LI THU VIEN --------" << endl;
    cout << "0: ket thuc" << endl;
    cout << "1: Nhap doc gia tre em" << endl;
    cout << "2: Nhap doc gia nguoi lon" << endl;

    while (true)
    {
        do
        {
            cout << endl
                 << "Nhap lua chon: ";
            cin >> lua_chon;
            cin.ignore();
        } while (lua_chon < 0 || lua_chon > 2);
        DocGia *x;
        switch (lua_chon)
        {
        case 0:
            return;
        case 1:
            x = new DocGiaTreEm;
            x->input();
            ds_docgia.push_back(x);
            break;
        case 2:
            x = new DocGiaNguoiLon;
            x->input();
            ds_docgia.push_back(x);
            break;
        }
    }
}

void ThuVien::output()
{
    cout << "Thong tin doc gia tre em" << endl;
    for (DocGia* x : ds_docgia)
    {
        x->output();
    }
}

int ThuVien::tinh_tong_tien_lam_the()
{
    int sum = 0;
    for (DocGia* x : ds_docgia)
        sum = sum + x->tinh_tien_lam_the();
    return sum;
}

int main()
{
    ThuVien *x = new ThuVien;
    x->input();
    x->output();
    cout << endl;
    cout << "tong tien lam the: " << x->tinh_tong_tien_lam_the();
}
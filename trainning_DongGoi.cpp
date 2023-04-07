#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class SinhVien
{
    friend class GiaoVien;

private:
    string id, ten, ns;
    double gpa;
    static int dem;

public:
    void nhap();
    void xuat();
    friend istream &operator>>(istream &in, SinhVien &a);
    friend ostream &operator<<(ostream &out, SinhVien a);
    bool operator < (SinhVien a);
};

bool SinhVien::operator < (SinhVien a)
{
   return this->gpa > a.gpa;
}

istream &operator>>(istream &inne, SinhVien &a)
{
    cout << "Nhap id: ";
    inne >> a.id;
    cout << "Nhap ten: ";
    inne.ignore();
    getline(inne, a.ten);
    cout << "Nhap ns: ";
    getline(inne, a.ns);
    cout << "Nhap gpa: ";
    inne >> a.gpa;
    return inne;
}

ostream &operator<<(ostream &out, SinhVien a)
{
    out << a.id << " " << a.ten << " " << a.ns << " " << a.gpa << endl;
    return out;
}

// SinhVien::SinhVien()
// {
//     id = ten = ns = "";
//     gpa = 0;
// }

int SinhVien::dem = 0;

// SinhVien::SinhVien(string ma, string name, string birth, double diem)
// {
//     cout <<"Ham khoi tao co tham so duoc goi" << endl;
//     id = ma;
//     ten = name;
//     ns = birth;
//     gpa = diem;
// }

void SinhVien::nhap()
{
    cout << "Gpa: ";
    cin >> gpa;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, ten);
    cout << "Ngay sinh: ";
    getline(cin, ns);
    ++dem;
    id = "SV" + string(3 - to_string(dem).length(), '0') + to_string(dem);
}

void SinhVien::xuat()
{
    cout << ten << " " << ns << " " << id << " " << gpa << endl;
}

// double SinhVien::getGpa()
// {
//     return gpa;
// }

// void chuanHoa(SinhVien &a)
// {
//     string res = "";
//     stringstream ss(a.ten);
//     string token;
//     while (ss >> token)
//     {
//         res += toupper(token[0]);
//         for (int i = 1; i < token.length(); i++)
//         {
//             res += tolower(token[i]);
//         }
//         res += " ";
//     }
//     res.erase(res.length() - 1);
//     a.ten = res;
// }

// SinhVien::~SinhVien()
// {
//     // cout << "Doi tuong duoc huy tai day" << endl;
// }

class GiaoVien
{
private:
    string khoa;

public:
    void update(SinhVien &);
};

void GiaoVien::update(SinhVien &x)
{
    x.gpa = 9.9;
}

class SoPhuc
{
    private:
        int thuc, ao;
    public:
        friend istream& operator >> (istream& in, SoPhuc& a);
        friend ostream& operator << (ostream& out, SoPhuc a);
        SoPhuc operator + (SoPhuc another);
};

istream& operator >> (istream& in, SoPhuc& a)
{
    in >> a.thuc >> a.ao;
    return in;
}

ostream& operator << (ostream& out, SoPhuc a)
{
    out << a.thuc <<" + " << a.ao << "i" << endl;
    return out;
}

SoPhuc SoPhuc::operator+(SoPhuc another)
{
    SoPhuc tong;
    tong.thuc = this->thuc + another.thuc;
    tong.ao = this->ao + another.ao;
    return tong;
}

int main()
{
    SoPhuc a;
    SoPhuc b;
    cin >> a >> b;
    SoPhuc tong = a+b;
    cout << tong;
}
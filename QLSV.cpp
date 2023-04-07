#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class SinhVien
{
private:
    string masv, hoten, lop, ns;
    float gpa;

public:
    SinhVien();
    friend istream &operator>>(istream &in, SinhVien &a);
    friend ostream &operator<<(ostream &out, SinhVien a);
    void chuanHoa();
};

istream &operator>>(istream &in, SinhVien &a)
{
    a.masv = "B20DCCN001";
    cout << "Ho ten: ";
    getline(in, a.hoten);
    cout << "Lop: ";
    getline(in, a.lop);
    cout << "Ngay sinh: ";
    getline(in, a.ns);
    cout << "Gpa: ";
    in >> a.gpa; in.ignore();
    return in;
}

ostream &operator<<(ostream &out, SinhVien a)
{
    out << a.masv << "\t" << a.hoten << "\t" << a.lop << "\t" << a.ns << "\t" << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

SinhVien::SinhVien()
{
    masv = hoten = lop = ns = "";
    gpa = 0;
}

void SinhVien::chuanHoa()
{
    string temp = "";
    stringstream ss(ns);
    string token;
    while (getline(ss, token, '/'))
    {
        int thieu = 2 - token.length();
        if (thieu >= 0)
            temp += string(thieu, '0') + token + "/";
        else
            temp += "00/";
    }
    temp.erase(temp.length() - 3, temp.length() - 1);
    temp += string(4 - token.length(), '0') + token;
    ns = temp;
}

int main()
{
    vector<SinhVien> v;
    SinhVien tmp;
    while(cin >> tmp)
    {
        v.push_back(tmp);
    }
    for(SinhVien x:v)
    {
        cout << x;
    }
}
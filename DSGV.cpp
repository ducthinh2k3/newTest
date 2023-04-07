#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class GiangVien
{
private:
    string ma, hoten, bomon;

public:
    GiangVien();
    static int cnt;
    void nhap();
    void xuat();
};

int GiangVien::cnt = 0;

GiangVien::GiangVien()
{
    ma = hoten = bomon = "";
}

void GiangVien::nhap()
{
    cnt++;
    ma = "GV" + string(2 - to_string(cnt).length(), '0') + to_string(cnt);
    cout << "Ho ten: ";
    getline(cin, hoten);
    cout << "Bo mon: ";
    getline(cin, bomon);
}

void GiangVien::xuat()
{
    cout << ma << "\t" << hoten << "\t" << bomon << "\t" << endl;
}

string chuanHoa(string s)
{
    stringstream ss(s);
    string temp;
    string token;
    while (ss >> token)
    {
        temp += toupper(token[0]);
    }
    return temp;
}

string getName(string name)
{
    stringstream ss(name);
    string temp, token;
    while(ss >> token)
        temp = token;
    return temp;
}

int main()
{
}
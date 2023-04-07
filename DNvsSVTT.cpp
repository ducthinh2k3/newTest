#include <iostream>
#include <string>
using namespace std;

class DoanhNghiep
{
private:
    string ma, ten;
    int sl;

public:
    friend istream &operator>>(istream &in, DoanhNghiep &a);
    friend ostream &operator<<(ostream &out, DoanhNghiep a);
};

istream &operator>>(istream &in, DoanhNghiep &a)
{
    cout << "Ma: ";
    in >> a.ma;
    in.ignore();
    cout << "Ten: ";
    getline(in, a.ten);
    cout << "Sl: ";
    in >> a.sl;
    return in;
}

ostream &operator<<(ostream &out, DoanhNghiep a)
{
    out << a.ma << "\t" << a.ten << "\t" << a.sl << endl;
    return out;
}

int main()
{
    int n;
    cin >> n;
    DoanhNghiep a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
    }
}
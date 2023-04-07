#include "DocGia.h"
#include <string>

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
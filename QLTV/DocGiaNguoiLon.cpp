#include "DocGiaNguoiLon.h"
#include <string>

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
    return getThang()*10000;
}
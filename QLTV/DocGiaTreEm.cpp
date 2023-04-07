#include "DocGiaTreEm.h"
#include <string>

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
    return getThang()*5000;
}
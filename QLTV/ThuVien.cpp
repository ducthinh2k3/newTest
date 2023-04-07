#include "ThuVien.h"

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
            cin >> lua_chon;
            cin.ignore();
        } while (lua_chon < 0 || lua_chon > 2);

        if (lua_chon == 1)
        {
            DocGiaTreEm x;
            x.input();
            doc_gia_tre_em.push_back(x);
        }
        else if (lua_chon == 2)
        {
            DocGiaNguoiLon x;
            x.input();
            doc_gia_nguoi_lon.push_back(x);
        }
        else
            return;
    }
}

void ThuVien::output()
{
    cout << "Thong tin doc gia tre em" << endl;
    for (DocGiaTreEm x : doc_gia_tre_em)
    {
        x.output();
    }

    cout << "Thong tin doc gia nguoi lon" << endl;
    for (DocGiaNguoiLon x : doc_gia_nguoi_lon)
    {
        x.output();
    }
}
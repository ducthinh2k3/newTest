#ifndef GAME_H //ensuring that this object is only initialized once
#define GAME_H 

#include "DocGiaTreEm.h"
#include "DocGiaNguoiLon.h"
#include <iostream>
#include <vector>
using namespace std;

class ThuVien
{
private:
    vector<DocGiaTreEm> doc_gia_tre_em;
    vector<DocGiaNguoiLon> doc_gia_nguoi_lon;
public:
    void input();
    void output();
    int tinh_tong_tien_lam_the();
    ThuVien();
    ~ThuVien();
};

#endif
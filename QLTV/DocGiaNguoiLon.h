#ifndef GAME_H //ensuring that this object is only initialized once
#define GAME_H 

#include <iostream>
#include "DocGia.h"

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

#endif
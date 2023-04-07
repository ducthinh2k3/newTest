#ifndef GAME_H //ensuring that this object is only initialized once
#define GAME_H 

#include "DocGia.h"
#include <iostream>
using namespace std;

class DocGiaTreEm : public DocGia
{
private:
    string ho_ten_dd;

public:
    void input();
    void output();
    int tinh_tien_lam_the();
    DocGiaTreEm();
    ~DocGiaTreEm();
};

#endif
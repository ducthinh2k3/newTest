#ifndef GAME_H //ensuring that this object is only initialized once
#define GAME_H 

#include <iostream>
using namespace std;

class DocGia
{
private:
    string ho_ten, ngay_lap;
    int so_thang;

public:
    void input();
    void output();
    int getThang();
    DocGia();
    ~DocGia();
};

#endif

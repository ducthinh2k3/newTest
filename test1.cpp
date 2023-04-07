#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class A
{
    public:
        virtual void xuat();
        virtual void tinhtoan() = 0;
};

void A::xuat()
{
    cout << "A";
}

class B : public A
{
    public:
        void xuat();
        void tinhtoan();
};

void B::tinhtoan()
{
    cout <<"Da tinh xong" << endl;
}

void B::xuat()
{
    cout << "B";
}

class C : public A
{
    public:
        void xuat();
};

void C::xuat()
{
    cout << "C";
}


int main()
{   
    A *x = new C;
    x->tinhtoan();
}
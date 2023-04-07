#include <iostream>
using namespace std;

class A
{
    private:
        int xa = 1;
    protected:
        int ya = 2;
    public:
        int za =3;
        void fa()
        {
            cout << xa << ya << za << endl;
        }
        void xuat()
        {
            cout << "Lop A" << endl;
        };
};

class B : public A
{
    private:
        int xb = -1;
    protected:
        int yb = -2;
    public:
        int zb = -3;
        void fb()
        {
            cout << xb << yb << zb << endl;
            cout << "Ben A ne: " << A::za << endl;    
        }
        void xuat()
        {
            cout << "Lop B" << endl;
        };

};


int main()
{
    A a;
    B b;
    // b.fb();
    // // Gọi cách này được
    // cout << b.A::za;
    b.xuat();


}
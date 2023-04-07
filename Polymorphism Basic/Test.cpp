#include <iostream>
using namespace std;

class A
{
    public:
        A()
        {
            cout << "Ham khoi tao A" << endl;
        };
        virtual ~A()
        {
            cout << "Ham huy A" << endl;
        };
        virtual void Xuat()
        {
            cout << "A day" <<endl;
        };
};

class B : public A
{
    public:
        B()
        {
            cout << "Ham khoi tao B" << endl;
        };
        ~B()
        {
            cout << "Ham huy B" << endl;
        };
        void Xuat()
        {
            cout << "B day" <<endl;
        };
};

class C : public A
{
    public:
        void Xuat()
        {
            cout << "C day" <<endl;
        };
};

int main()
{
    A* x = new B;
    x->Xuat();
    delete x;
}
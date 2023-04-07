#include <iostream>
using namespace std;

class MangSoNguyen
{
    private:
        int *a;
        int n;
    public:
        MangSoNguyen();
        ~MangSoNguyen(void);
        MangSoNguyen(const MangSoNguyen &m);
        void Nhap();
};

MangSoNguyen::~MangSoNguyen(void)
{
    if(a!=NULL)
    {
        delete[] a;
        a = NULL;
    }
}

MangSoNguyen::MangSoNguyen(void)
{

}

MangSoNguyen::MangSoNguyen(const MangSoNguyen &m)
{
    if(m.a == NULL)
    {
        a = NULL;
        n = 0;
    }
    else
    {
        n = m.n;
        a = new int[n];
        for(int i=0; i<n; i++)
        {
            a[i] = m.a[i];
        }
    }
}

void MangSoNguyen::Nhap()
{
    cout << "Nhap n: ";
    cin >> n;
    a = new int[n];
    for(int i=0; i<n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}

int main()
{
    MangSoNguyen m1;
    m1.Nhap();
    MangSoNguyen m2 = m1;   
}
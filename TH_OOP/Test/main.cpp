#include "Functions.h"
#include "Fraction.h"

int main()
{
    // Bài 1
    cout << "--------- Bài 1 -----------" << endl;
    int sizeReal;
    cout << "Nhap vao so lan muon them: ";
    cin >> sizeReal;

    // Stack<int>
    cout << "-------- Stack<int> ---------" << endl;
    Stack<int> si;
    int number;
    for (int i = 0; i < sizeReal; i++)
    {
        cout << "Nhap phan tu " << i << ": ";
        cin >> number;
        si.push(number);
    }

    cout << endl
         << "Lay gia tri top value: ";
    if (!si.isEmpty())
    {
        cout << si.getTop() << endl;
    }
    else
    {
        cout << "Stack dang rong" << endl;
    }

    cout << endl
         << "Xuat phan tu trong ngan xep: " << endl;
    cout << "Nhap so phan tu muon lay: ";
    int numberGet = 0;
    cin >> numberGet;
    for (int i = 0; i < numberGet; i++)
    {
        if (!si.isEmpty())
            cout << si.pop() << endl;
        else
        {
            cout << "Stack dang rong" << endl;
            break;
        }
    }

    // Stack<Fraction>
    cout << "-------- Stack<Fraction> ---------" << endl;
    Stack<Fraction> sf;
    Fraction p;
    for (int i = 0; i < sizeReal; i++)
    {
        cout << "Nhap phan tu " << i << ": " << endl;
        cin >> p;
        sf.push(p);
    }

    cout << endl
         << "Lay gia tri top value: ";
    if (!sf.isEmpty())
    {
        cout << sf.getTop();
    }
    else
    {
        cout << "Stack dang rong" << endl;
    }

    cout << endl
         << "Xuat phan tu trong ngan xep: " << endl;
    cout << "Nhap so phan tu muon lay: ";
    cin >> numberGet;
    for (int i = 0; i < numberGet; i++)
    {
        if (!sf.isEmpty())
            cout << sf.pop();
        else
        {
            cout << "Stack dang rong" << endl;
            break;
        }
    }
}
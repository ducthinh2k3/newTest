#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *data;
    int topIndex;
    int capacity;

public:
    Stack();
    Stack(int n);   
    ~Stack();
    void clear();
    bool isFull();
    bool isEmpty();
    void push(const T &item);
    T pop();
    T getTop();
};

template <class T>
Stack<T>::Stack()
{
    int size = 0;
    cout << "Nhap vao kich thuoc Stack: ";
    cin >> size;
    capacity = size;
    data = new T[size];
    topIndex = -1;
}

template <class T>
Stack<T>::Stack(int n)
{
    capacity = n;
    data = new T[n];
    topIndex = -1;
}

template <class T>
Stack<T>::~Stack()
{
    capacity = 0;
    topIndex = -1;
    delete[] data;
}

template <class T>
void Stack<T>::clear()
{
    capacity = 0;
    topIndex = -1;
    delete[] data;
}

template <class T>
bool Stack<T>::isFull()
{
    if (topIndex == capacity - 1)
        return true;
    return false;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (topIndex == -1)
        return true;
    return false;
}

template <class T>
void Stack<T>::push(const T &item)
{
    if (!isFull())
    {
        topIndex++;
        data[topIndex] = item;
    }
}

template <class T>
T Stack<T>::pop()
{
    T result;
    if (!isEmpty())
    {
        result = data[topIndex];
        topIndex--;
    }
    return result;
}

template <class T>
T Stack<T>::getTop()
{
    T result;
    if (!isEmpty())
    {
        result = data[topIndex];
    }
    return result;
}

class Fraction
{
private:
    int tu, mau;

public:
    Fraction();
    friend istream &operator>>(istream &in, Fraction &f);
    friend ostream &operator<<(ostream &out, Fraction f);
    ~Fraction();
};

Fraction::Fraction()
{
    tu = 0;
    mau = 1;
}

istream &operator>>(istream &in, Fraction &f)
{
    cout << "tu so: ";
    cin >> f.tu;

    do
    {
        cout << "mau so (Khac 0): ";
        cin >> f.mau;
    } while (f.mau == 0);
    return in;
}

ostream &operator<<(ostream &out, Fraction f)
{
    cout << f.tu << "/" << f.mau << endl;
    return out;
}

Fraction::~Fraction()
{
    tu = 0;
    mau = 1;
}

int main()
{
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
    if(!si.isEmpty())
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
        if(!si.isEmpty())
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
    if(!sf.isEmpty())
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
        if(!sf.isEmpty())
            cout << sf.pop();
        else
        {
            cout << "Stack dang rong" << endl;
            break;
        }
    }
}

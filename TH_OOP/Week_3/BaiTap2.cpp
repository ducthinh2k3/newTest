#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int topIndex;
    int size;

public:
    Stack(int size);
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int getTopValue();
    int getTopIndex();
    ~Stack();
};

Stack::Stack(int size)
{
    this->size = size;
    this->arr = new int[this->size];
    this->topIndex = -1;
}

bool Stack::isEmpty()
{
    if (topIndex == -1)
        return 1;
    return 0;
}

bool Stack::isFull()
{
    if (topIndex == size - 1)
        return 1;
    return 0;
}

void Stack::push(int data)
{
    if (!isFull())
    {
        topIndex++;
        arr[topIndex] = data;
    }
}

int Stack::pop()
{
    int res = 0;
    if (!isEmpty())
    {
        res = arr[topIndex];
        topIndex--;
    }
    return res;
}

int Stack::getTopValue()
{
    int res = 0;
    if (!isEmpty())
    {
        res = arr[topIndex];
    }
    return res;
}

Stack::~Stack()
{
    size = 0;
    topIndex = -1;
    delete[] arr;
}

int Stack::getTopIndex()
{
    return topIndex;
}

int main()
{
    // Stack s(7);
    // int value;
    // s.push(12);
    // s.push(11);
    // s.push(22);
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(7);
    // for (int i = 0; i <= s.getTopIndex(); i++)
    // {
    //     value = s.getTopValue();
    //     cout << value << endl;
    // }

    // while (!s.isEmpty())
    // {
    //     value = s.pop();
    //     cout << value << endl;
    // }

    int sizeStack, sizeReal, number;
    cout << "Nhap vao size Stack: ";
    cin >> sizeStack;
    cout << "Nhap vao so lan muon them: ";
    cin >> sizeReal;

    Stack s(sizeStack);
    for(int i=0; i<sizeReal; i++)
    {
        cout << "Nhap phan tu " << i << ": ";
        cin >> number;
        s.push(number);
    }

    cout << "Lay gia tri top value: ";
    if(!s.isEmpty())
    {
        cout << s.getTopValue() << endl;
    }

    cout << "Xuat tat ca phan tu trong ngan xep: " << endl;
    while(!s.isEmpty())
    {
        number = s.pop();
        cout << number << endl;
    }
}

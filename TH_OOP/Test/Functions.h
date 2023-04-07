#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T* data;
    int topIndex;
    int capacity;

public:
    Stack();
    Stack(int n);
    ~Stack();
    void clear();
    bool isFull();
    bool isEmpty();
    void push(const T& item);
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
void Stack<T>::push(const T& item)
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


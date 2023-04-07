#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int frontIndex, rearIndex;
    int size;

public:
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enQueue(int data);
    int getFrontValue();
    int deQueue();
};

Queue::Queue(int size)
{
    this->size = size;
    arr = new int[size];
    frontIndex = 0;
    rearIndex = -1;
}

Queue::~Queue()
{
    delete[] arr;
}

bool Queue::isEmpty()
{
    if (frontIndex > rearIndex)
        return true;
    return false;
}

bool Queue::isFull()
{
    if (rearIndex == size - 1)
        return true;
    return false;
}

void Queue::enQueue(int data)
{
    if (!isFull())
    {
        rearIndex += 1;
        arr[rearIndex] = data;
    }
}

int Queue::deQueue()
{
    int res = 0;
    if(!isEmpty())
    {
        res = arr[frontIndex];
        frontIndex++;
        
    }
    else
    {
        frontIndex = 0;
        rearIndex = -1;
    }
    return res;
}

int Queue::getFrontValue()
{
    int res = 0;
    if(!isEmpty())
    {
        res = arr[frontIndex];
    }
    return res;
}

int main()
{
    int sizeQueue, sizeReal, number;
    cout << "Nhap vao size Queue: ";
    cin >> sizeQueue;
    cout << "Nhap vao so lan muon them: ";
    cin >> sizeReal;

    Queue q(sizeQueue);
    for(int i=0; i<sizeReal; i++)
    {
        cout << "Nhap phan tu " << i << ": ";
        cin >> number;
        q.enQueue(number);
    }

    cout << "Lay gia tri front value: ";
    if(!q.isEmpty())
    {
        cout << q.getFrontValue() << endl;
    }

    cout << "Xuat tat ca phan tu trong hang doi: " << endl;
    while(!q.isEmpty())
    {
        number = q.deQueue();
        cout << number << endl;
    }
    
}

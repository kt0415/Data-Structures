#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "QUEUE IS FULL\n";
        }

        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "QUEUE IS EMPTY\n";
            return -1;
        }

        else
        {
            int x = arr[front];
            front++;
            return x;
        }
    }

    int front()
    {
        if(!isempty())
            return arr[front];
        return -1;
    }

    bool isempty()
    {
        if (front == rear)
            return true;
        return false;
    }

    bool isfull()
    {
        if (rear == size)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}
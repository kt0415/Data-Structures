#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    Node* front;
    Node* rear;
    int size;

    Queue()
    {
        size = 0;
        front = NULL;
        rear = NULL;
    }

    void push(int x)
    {
        Node* temp = new Node(x);
        if(front == NULL)
        {
            front = temp;
            rear = temp;   
        }

        else
        {
            rear -> next = temp;
            rear = temp;
        }

        size++;
    }

    int pop()
    {
        if(front==NULL) return -1;

        int x = front -> data;
        Node* temp = front;
        front = front -> next;
        delete temp;
        size--;
        return x;
    }

    int queueTop()
    {
        return front == NULL ? -1 : front -> data;
    }

    int queueSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return front==NULL;
    }
};

int main()
{

    return 0;
}
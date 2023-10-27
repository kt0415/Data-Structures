#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)         //constructor
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()            //destructor
    {
        int val = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is freed for the node with data: "<<val<<endl;
    }
};

void InsertNode(Node*&tail, int cmp, int d)     //using a cmp variable to compare while traversing through the linked list during insertion
{
    Node*temp = new Node(d);

    if(tail==NULL)  //empty linked list
    {
        tail = temp;
        temp->next = temp;
    }

    else        //non empty linked list
    {
        Node*curr = tail;

        while(curr->data != cmp)
        {
            curr = curr->next;
        }

        //element found
        temp->next = curr->next;
        curr->next = temp;
    }
} 

void DeleteNode(Node*&tail, int val)
{
    if(tail == NULL)
    {
        return;
    }

    else
    {       //assuming the value to be deleted in present in linked list
        Node*prev = tail;
        Node*curr = prev->next;


        while(curr->data != val)    //traversing until current pointer points the value to be deleted
        {
            prev = curr;        //shifting the previous pointer forward
            curr = curr->next;  //shifting the current pointer forward
        }

        //here our current is pointing to the node / value to be deleted
        prev->next = curr->next;

        if(curr == prev)
        {
            tail == NULL;
        }

        if(tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;

    }
}

void print(Node*&tail)
{                       //printing the elements of linked list until we complete the cycle
    Node*loc = tail;
    if(tail == NULL)
    {
        cout<<"LINKED LIST IS EMPTY\n";
        return;
    }        

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail!=loc);
    cout<<endl;
}

int main()
{
    Node*tail = NULL;

    InsertNode(tail,3,1);
    print(tail);

    InsertNode(tail,1,2);
    print(tail);

    InsertNode(tail,2,5);
    print(tail);

    InsertNode(tail,2,4);
    print(tail);

    DeleteNode(tail,5);
    print(tail);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d) // constructor
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()     //destructor
    {
        int val = this->data;
        if(next!=NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is freed for the node with the data: " << val << endl;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtTail(Node*&head, Node *&tail, int d)
{
    Node *temp = new Node(d); // 1)Created a new node named temp

    if(tail == NULL)
    {
        tail = temp;
        head = temp;
    }

    else
    {
        tail->next = temp; // 2) made the last element of existing linked list point to temp
        temp->prev = tail; // 3) made the prev pointer of temp point to existing last element
        tail = temp;       // 4) shift the tail to temp thus making temp as last element
    }
}

Node* reverse(Node*&head, Node*&tail)
{
    Node*pre = NULL;
    Node*post = NULL;
    Node*curr = head;

    while(curr!=NULL)
    {
        post = curr->next;
        curr->next = pre;
        pre->prev = curr;

        pre = curr;
        curr = post;
    }

    return pre;
}

int main()
{
    Node*node1 = new Node(10);
    Node*head = node1;
    Node*tail = node1;

    InsertAtTail(head,tail,6);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,8);
    InsertAtTail(head,tail,1);
    InsertAtTail(head,tail,2);

    print(head);
    head = reverse(head,tail);
    print(head);
    
    return 0;
}

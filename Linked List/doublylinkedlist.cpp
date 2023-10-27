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

// traversing a linked list
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

// getting the length of a linked list
int getlength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

void InsertAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d); // 1) Created a new node named temp
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        temp->next = head; // 2) made the temp's next pointer point to head(1st node of existing linked list)
        head->prev = temp; // 3) made the head's prev pointer point to temp
        head = temp;       // 4) shifted the head from the existing 1st node to our newly created node that now will be the 1st node
    }
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

void InsertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1) // inserting at the beginning
    {
        InsertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    if (temp->next == NULL) // if position is set to the last value of LL, we call InsertAtTail() and return
    {
        InsertAtTail(head, tail, d);
        return;
    }

    while (cnt < pos - 1) // while we don't reach the desired position
    {
        temp = temp->next; // we make the temp pointer point to the next node.
        cnt++;             // increment the count for each iteration
    }

    Node *x = new Node(d); // creating a new node that is to be inserted at our desired position
    x->next = temp->next;  // making the new node's next point to the node to the node next to the temp
    temp->next->prev = x;  // making the prev pointer of the node next to temp to point to x (temp ke next node ka prev)
    temp->next = x;        // making the next pointer of temp to point to x
    x->prev = temp;        // making the prev of x to point to temp
}

void deleteNode(Node *&head, int pos)
{
    if(pos == 1)
    {
        Node*temp = head;           //initially assigning 1st node(temp) to head as we want to delete the first node
        temp->next->prev = NULL;    //making the 2nd node's previous pointer point to NULL
        head = temp->next;          //shifting the head to node 2
        temp->next = NULL;          //making the 1st node(temp's) next pointer NULL
        delete temp;                //deleting the 1st node
    }

    else
    {   //to delete any node except the first node, we require 2 pointers : current and previous
        Node*curr = head;   //the current pointer initially points to node at head
        Node*prev = NULL;   //the previous pointer is made NULL initially

        int cnt = 1;        //to traverse through linked list until we reach the node to be deleted, we use a counter cnt with initial value 1
        while(cnt<pos)      //shifting our both pointers until we reach the node to be deleted
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;    //making the node prev to node to be deleted{aka curr node} to point to the node after curr node
        curr->next = NULL;          //making the curr node's next point to NULL
        delete curr;                //deleting the current [desired] node
    }
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;

    // print(head);
    // cout<<getlength(head)<<endl;

    InsertAtHead(head,tail,2);
    InsertAtHead(head,tail,7);
    InsertAtTail(head, tail, 10);
    InsertAtPosition(head, tail, 2, 15);
    InsertAtPosition(head, tail, 4, 11);
    print(head);

    deleteNode(head,6);
    print(head);

    return 0;
}
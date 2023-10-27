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

    ~Node()             //destructor
    {
        int val = this->data;
        if(this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

// printing the entire linked list
void print(Node *&head) // traversing through a linked list and printing its elements
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// inserting an element at the end of linked list
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d); // creating a new node
    if (tail == NULL)
    {
        tail = temp;
    }

    else
    {
        tail->next = temp; // assigning the address of existing last node where initially tail was pointing to make it point to the new node created
        tail = temp;       // shifting the tail to the newly added node(current last node) from the ex-last node for upcoming tail insertions
    }
}

Node* reverse(Node*head)    //theoritical explaination in the notebook ...TC:O(n); SC:O(1) ...iterative approach
{                           //iterating using 3 pointers prev,curr,fwd
    Node*prev = NULL;       //prev initially points to NULL
    Node*curr = head;       //curr points to head at the beginning
    Node*fwd = NULL;        //fwd points to NULL

    while(curr!=NULL)       //until curr points NULL
    {
        fwd = curr->next;   
        curr->next = prev;  //make current node points previous node
        prev = curr;        //shifting prev to curr posn
        curr = fwd;         //shifting curr to fwd posn
    }

    return prev;            //returning the prev that is now pointing to last node of existing LL which is the first node of new LL
}

int main()
{
    Node* node1 = new Node(5);
    Node*head = node1;
    Node*tail = node1;

    InsertAtTail(tail,4);
    InsertAtTail(tail,7);
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,8);

    print(head);
    head = reverse(head);       //head is shifted to its new posn here and linked list is reversed successfully
    cout<<"AFTER REVERSING: "<<endl;
    print(head);
    return 0;
}
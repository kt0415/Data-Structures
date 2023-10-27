#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node() // destructor
    {
        int value = this->data;
        if (this->next != NULL) // freeing the memory
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is freed for the node with the data " << value << endl;
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

// inserting an element at the beginning of linked list
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d); // creating a new node

    if (head == NULL)
    {
        head = temp;
    }

    else
    {
        temp->next = head; // making the new node point to the 1st node of existing linked list
        head = temp;       // shifting the head to the newly added node(current 1st node) from the ex-first node for upcoming head insertions
    }
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

// inserting an element at a specific position in the linked list
void InsertAtPosition(Node *&head, Node *&tail, int position, int d) // to insert a node at a specific position, we are traversing through the linked list until we reach that position.
{
    if (position == 1) // if position is set to 1, we call the InsertAtHead() and return
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head; // initially making a temp pointer to point at 1st node
    int cnt = 1;       // count variable for checking if we have reached the posn/not

    if (temp->next == NULL) // if position is set to the last value of LL, we call InsertAtTail() and return
    {
        InsertAtTail(tail, d);
        return;
    }

    while (cnt < position - 1) // while we don't reach the desired position
    {
        temp = temp->next; // we make the temp pointer point to the next node.
        cnt++;             // increment the count for each iteration
    }

    Node *x = new Node(d); // creating a new node that is to be inserted at our desired position
    x->next = temp->next;  // once temp reaches the node before the position, we make our new node point to the node that was previously at that position
    temp->next = x;        // then we make our temp to point to our new node thus inserting the element successfully at the position desired
}

// deleting an element from the linked list
void deleteNode(Node *&head, int position)
{
    if (position == 1) // deleting the first node
    {
        Node *temp = head; // here we declare a new node temp that is pointing to the first node of linked list
        head = head->next; // then we shift our head pointer from first node of linked list to the 2nd node of linked list
        temp->next = NULL; // then we make the temp node to point to NULL which before was pointing to the 2nd node of linked list
        delete temp;       // then we delete the node.
    }

    else // deleting middle or any last node
    {
        Node *curr = head; // here we are assigning the current node to point to head
        Node *prev = NULL; // here we are assigning the previous node to point to NULL

        int cnt = 1; // now we iterate till we reach the position from where we want to delete the element
        while (cnt < position)
        {
            prev = curr;       // during this we make the previous to point to the node to which current was pointing
            curr = curr->next; // and we make current point to the next node in the linked list
            cnt++;
        }

        prev->next = curr->next; // once we reach the position, we make previous node to point to the position where current node was pointing
        curr->next = NULL;       // then we make the current node(to be deleted) to point to NULL which was initially pointing to the next node in the linked list.
        delete curr;             // then we delete the current node
    }
}

int main()
{
    // creating a new node
    Node *node1 = new Node(5);
    // head pointing to new node
    Node *head = node1;
    // tail pointing to new Node
    Node *tail = node1;

    // InsertAtHead(head, 11);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 31);
    // print(head);

    InsertAtPosition(head, tail, 2, 15);
    print(head);

    deleteNode(head, 3);
    print(head);

    return 0;
}
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

struct Stack
{
    Node* top;
    int size;

    Stack()
    {
        top = NULL;
        size = 0;    
    }

    void push(int x)
    {
        Node* ele = new Node(x);
        ele -> next = top;
        top = ele;
        size++;
        cout<<"Pushed "<<x<<" in the stack!\n";
    }

    int pop()
    {
        if(top == NULL) return -1;

        Node* temp = top;
        int x = temp -> data;
        top = top -> next;
        temp -> next = NULL;
        delete temp;
        size--;
        cout<<"Element popped: "<<x<<endl;
        return x;
    }

    int stackTop()
    {
        if(top == NULL) return -1;
        cout<<"Element at the top: "<<top->data<<endl;
        return top -> data;
    }

    int stackSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void printStack()
    {
        Node* curr = top;
        cout<<"Stack: ";
        while(curr!=NULL)
        {
            int x = curr -> data;
            cout<<x<<" ";
            curr = curr -> next;
        }
        cout<<endl;
    }
};


int main()
{
    Stack st;
    st.push(10);
    st.printStack();
    st.push(3);
    st.printStack();
    st.push(5);
    st.printStack();
    st.pop();
    st.printStack();
    st.stackTop();
    st.pop();
    cout<<"Current Size of stack is: "<<st.stackSize()<<endl;
    st.printStack();
    cout<<st.isEmpty();
    return 0;
}
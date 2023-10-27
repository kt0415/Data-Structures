#include <bits/stdc++.h>
using namespace std;

class Stack
{
    private:
        int size;
        int *arr;
        int top;
    
    public:
        Stack(int size)
        {
            this->top = -1;
            this->size = size;
            this->arr = new int[size];
        }

        void push(int ele)
        {
            if(top < size)
            {
                top++;
                arr[top] = ele;
            }

            else
            {
                cout<<"Stack is Full\n";
            }
        }

        int pop()
        {
            if(top>-1)
            {
                int x = arr[top];
                top--;
                return x;
            }

            else
            {
                cout<<"Stack is Empty\n";
                return -1;
            }
        }

        int Top()
        {
            if(top!= -1)
            {
                return arr[top];
            }

            else
            {
                cout<<"Stack is Empty\n";
                return -1;
            }
        }

        int cur_size()
        {
            return top+1;
        }

        bool isEmpty()
        {
            return top == -1;
        }

        bool isFull()
        {
            return top == size-1;
        }

        void print()
        {
            for(int i=0; i<top+1; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    Stack st(5);
    st.push(4);
    st.print();
    st.push(1);
    st.print();
    st.push(3);
    st.print();
    int x = st.pop();
    cout<<x<<endl;
    st.print();
    int top = st.Top();
    cout<<top<<endl;
    cout<<st.isFull()<<endl;
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;

    return 0;
}
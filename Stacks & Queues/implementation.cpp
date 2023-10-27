#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    // properties
    int top;
    int *arr;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size; // this -> size represents the size corresponding to the class Stack and the RHS wala size is the parameter we passed
        arr = new int[size];
        top = -1;
    }

    void pushinstack(int d)
    {
        if(size-top>1)  //it means we have atleast 1 empty space where element can be inserted
        {
            top++;
            arr[top] = d;
        }

        else
        {
            cout<<"STACK OVERFLOW\n";
        }
    }

    void popfromstack()
    {
        if(top>-1)      //to check if stack isnt empty
            top--;

        else    
            cout<<"STACK IS EMPTY\n";
    }

    int topmost()
    {
        if(top>-1 && top<size)  //to check if stack isnt empty also that top isnt exceeding the stack size; basically setting the range of the stack
            return arr[top];    
    }

    bool is_stack_empty()
    {
        if(top==-1)
            return true;

        return false;
    }
};

int main()
{
    Stack st(5);
    st.pushinstack(32);
    st.pushinstack(44);
    st.pushinstack(69);

    cout<<st.topmost()<<endl;

    st.popfromstack();
     cout<<st.topmost()<<endl;

    return 0;
}
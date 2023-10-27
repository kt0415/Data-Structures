#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>s;    //stack creation
    
    //inserting an element in the stack
    s.push(2);
    s.push(5);
    s.push(3);

    //removing an element from the stack
    //only the first element can be removed
    s.pop();

    //viewing the topmost element of the stack
    cout<<s.top()<<endl;

    //checking if the stack is empty or not
    if(s.empty()==true)
        cout<<"EMPTY STACK\n";

    else
        cout<<"NOT EMPTY\n";

    //printing the size of the stack
    cout<<s.size()<<endl;

    return 0;
}
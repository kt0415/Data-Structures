#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>&s, int e)    //we wrote this recursive function so that our element e gets inserted at the bottom of the stack
{
    if(s.empty())       //base condition is that our stack s should be empty, then only we will push our element e in the stack and then return
    {
        s.push(e);
        return;
    }
    
    int num = s.top();  //unless which, we assign our top to a variable num 
    s.pop();            //then we pop the top of the stack 
    
    insert(s, e);       //we make a recursive call to insert func
    
    s.push(num);        //once the recursive call has terminated, we push our num back in the stack
    
}

void reverseStack(stack<int> &stack)    //here too, we are going to follow recursive approach
{
    // Write your code here
    if(stack.empty())      //base condition is that stack should be empty
        return;

        int x = stack.top();    //unless which, again like previously we assign the top value to an integer x
        stack.pop();            //we then pop the top value of the stack
        reverseStack(stack);    //recursive call is made unless base condition isn't met
        insert(stack,x);        //the taken element x is inserted at the bottom of the stack by user defined function insert()...
    
}
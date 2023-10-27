#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() 
    {
        stack<int>st1,st2;
        this->s1 = st1;
        this->s2 = st2;    
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty())  return -1;

        while(s1.size()!=1)
        {
            s2.push(s1.top());
            s1.pop();
        }

        int x = s1.top();
        s1.pop();

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return x;
    }
    
    int peek() {
        if(s1.empty())  return -1;

        while(s1.size()!=1)
        {
            s2.push(s1.top());
            s1.pop();
        }

        int x = s1.top();

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//Approach 1: Using 2 queues
//{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// class QueueStack{
// private:
//     queue<int> q1;
//     queue<int> q2;
// public:
//     void push(int);
//     int pop();
// };


// int main()
// {
//     int T;
//     cin>>T;
//     while(T--)
//     {
//         QueueStack *qs = new QueueStack();

//         int Q;
//         cin>>Q;
//         while(Q--){
//         int QueryType=0;
//         cin>>QueryType;
//         if(QueryType==1)
//         {
//             int a;
//             cin>>a;
//             qs->push(a);
//         }else if(QueryType==2){
//             cout<<qs->pop()<<" ";

//         }
//         }
//         cout<<endl;
//     }
// }

// // } Driver Code Ends


// /* The structure of the class is
// class QueueStack{
// private:
//     queue<int> q1;
//     queue<int> q2;
// public:
//     void push(int);
//     int pop();
// };
//  */

// //Function to push an element into stack using two queues.
// void QueueStack :: push(int x)
// {
//     q1.push(x);
// }

// //Function to pop an element from stack using two queues. 
// int QueueStack :: pop()
// {
//     if(q1.empty()) return -1;
    
//     while(q1.size()!=1)
//     {
//         q2.push(q1.front());
//         q1.pop();
//     }
    
//     int x = q1.front();
//     q1.pop();
    
//     while(!q2.empty())
//     {
//         q1.push(q2.front());
//         q2.pop();
//     }
    
//     return x;
// }

//Approach 2: Using 1 queue
// class MyStack {
// public:
//     queue<int>q;
//     MyStack() {
//         queue<int>Q;
//         this -> q = Q;
//     }
    
//     void push(int x) 
//     {
//         q.push(x);    
//     }
    
//     int pop() 
//     {
//         if(q.empty())   return -1;

//         int n = q.size();
//         for(int i=0; i<n-1; i++)
//         {
//             q.push(q.front());
//             q.pop();
//         }

//         int x = q.front();
//         q.pop();
//         return x;
//     }
    
//     int top() 
//     {
//         if(q.empty())   return -1;

//         int n = q.size();
//         for(int i=0; i<n-1; i++)
//         {
//             q.push(q.front());
//             q.pop();
//         }

//         int x = q.front();
//         q.pop();
//         q.push(x);
//         return x;
//     }
    
//     bool empty() 
//     {
//         return q.empty();    
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

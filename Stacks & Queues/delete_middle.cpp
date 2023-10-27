#include <bits/stdc++.h> 
using namespace std;

void deleteMiddle(stack<int>&inputStack, int N)
{
    int a = N - (N/2);
    vector<int>v;
    while(!inputStack.empty())
    {
        int x = inputStack.top();
        v.push_back(x);
        inputStack.pop();
    }
    
    v[N/2] = -1;
    reverse(v.begin(),v.end());

    for(int i=0; i<v.size(); i++)
    {
        if(v[i]>=0)
            inputStack.push(v[i]);   
    }
}
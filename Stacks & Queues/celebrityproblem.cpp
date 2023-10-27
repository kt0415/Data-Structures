#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool knows(vector<vector<int>>&M, int a, int b)
    {
        if(M[a][b]==1)
            return true;
        return false;
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        
        //step1: pushing all elements in stack
        for(int i=0; i<n; i++)
        {
            s.push(i);
        }
        
        //step2: comparing 2 elements whether they know each other until our stack has 1 member/element
        while(s.size()>1)
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            
            if(knows(M,x,y))
            {
                s.push(y);
            }
            
            else
            {
                s.push(x);
            }
        }
        
        //step3: single element is potential celebrity> verifying it
        int pc = s.top();
        
        bool checkrow = false, checkcol = false;
        int zero = 0, one = 0;
        for(int i=0; i<n; i++)
        {
            if(M[pc][i]==0)
                zero++;
        }
        
        if(zero == n)
            checkrow = true;
            
        for(int i=0; i<n; i++)
        {
            if(M[i][pc]==1)
                one++;
        }
        
        if(one == n-1)
            checkcol = true;
            
        if(checkrow && checkcol)
            return pc;
            
        return -1;
        
    }
};
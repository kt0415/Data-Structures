#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) 
{
    if(str.length()&1 == 1)    //if our string is not even, then { or }'s count will not be same... so they cant be made valid 
    {
        return -1;    //so we return -1 in this case
    }
    
    stack<char>st;    
    for(int i=0;i<str.length(); i++)
    {
        if(str[i] == '{')    //we push our opening brace in the stack
        {
            st.push(str[i]);
        }
        
        else
        {
            if(!st.empty() && st.top()=='{')//we check if our stack wasnt empty and our top element was a { brace, if it was so, our current position of string str[i] == '}' made a valid pair so we pop the top element from the stack of characters... we do so so that our stack contains only the invalid braces
            {
                st.pop();
            }
            
            else
            {
                st.push(str[i]);
            }
        }
    }
    //now we will traverse through the stack keeping a count of { & } present in it. The ans would be equal to (c + 1)/2 + (o+1)/2 where c is count of closed brace and o is count of open brace
    
    int c = 0, o = 0;    
    while(!st.empty())
    {
        if(st.top() == '}')
            c++;
        
        else
            o++;
        
        st.pop();
    }
    
    int ans = ((c+1)/2)  + ((o+1)/2);
    
    return ans;
}
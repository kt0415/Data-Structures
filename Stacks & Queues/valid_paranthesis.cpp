#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string exp)
{
    map<char,int>sym = {{'{',1},{'}',-1},{'[',2},{']',-2},{'(',3},{')',-3}};
    int n = exp.size();
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += sym[exp[i]];
    }
    
    if(sum!=0)
        return false;
    
    else
    {
        stack<char>st;
        for(int i=0; i<n; i++)
        {
            if(sym[exp[i]]>0)
                st.push(exp[i]);
        
            else if(st.empty() && sym[exp[i]]<0)
                return false;
            
            else
            {
                if(sym[exp[i]]+sym[st.top()]!=0)
                    return false;
                
                else
                {
                    if(!st.empty())
                        st.pop();
                
                    else
                        return false;
                }
            }
        }
    
        if(!st.empty())
            return false;
        
    return true;
    }
}
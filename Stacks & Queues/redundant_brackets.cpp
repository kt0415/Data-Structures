#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for(int i=0; i<s.length(); i++)    
    {
        char ch = s[i]; 
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')    //first we fill our stack with opening bracket and operators
        {
            st.push(ch);
        }
        
        else    /*then we check if the string had any closing brackets, for whom we traverse checking a flag initially set to true meaning there exists a redundant bracket in our stack{in our expression basically }*/
        {
            if(ch == ')')
            {
                bool flag = true;
                
                while(st.top()!='(')//we traverse in the stack unless we find an opening bracket at the top during which we check if there is atleast one operator present between the opening and closing bracket
                {
                    char t = st.top();
                    if(t == '+' || t == '-' || t == '*' || t == '/')
                    {
                        flag = false; //provided an operator is present between ( & ) we make our flag as false
                    }
                    st.pop();    //we pop the '(' from the stack and while loop continues... had our flag turned false for one pair of non redundant brackets, it is set to true again until our string ends.
                }
                
                if(flag == true)    //happens when there is no operator between ( & ) resulting in our flag to remain true ie: redundant brackets are present in our stack & therefore in the given string
                    return true;
                st.pop();    
            }
                
        }
    }
    
}

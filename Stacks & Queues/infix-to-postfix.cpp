#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if(ch == '^')   return 3;

    else if(ch == '*' || ch == '/') return 2;

    else if(ch == '+' || ch == '-') return 1;

    else    return -1;
}

string infixToPostfix(string&s)
{
    int n = s.size();
    stack<char>st;
    string ans = "";

    for(int i=0; i<n; i++)
    {
        char ch = s[i];

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            ans += ch;

        else if(ch == '(')  st.push(ch);

        else if(ch == ')')
        {
            while(st.top()!='(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while(!st.empty() && precedence(ch)<=precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string input;
    cout<<"Enter the infix expression: ";
    cin>>input;
    string output = infixToPostfix(input);
    cout<<"The postfix expression is: "<<output<<endl;
    return 0;
}
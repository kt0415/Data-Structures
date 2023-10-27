#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if(ch == '^')   return 3;

    else if(ch == '*' || ch == '/') return 2;

    else if(ch == '+' || ch == '-') return 1;

    else return -1;
}

string infixToPostfix(string& s)
{
    int n = s.size();
    stack<char>st;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if(isalpha(ch) || isdigit(ch))
        {
            ans += ch;
        }

        else if(ch == '(')
            st.push(ch);

        else if(ch == ')')
        {
            while(st.top()!= '(')
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

string infixToPrefix(string& infix)
{
    reverse(infix.begin(),infix.end());

    int n = infix.size();

    for (int i = 0; i < n; i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';

        else if(infix[i] == ')')
            infix[i] = '(';
    }
    
    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(),prefix.end());

    return prefix;
}

int main()
{
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    string postfix = infixToPostfix(infix);
    cout<<"The postfix expression is: "<<postfix<<endl;
    string prefix = infixToPrefix(infix);
    cout<<"The prefix expression is: "<<prefix<<endl;
    return 0;
}
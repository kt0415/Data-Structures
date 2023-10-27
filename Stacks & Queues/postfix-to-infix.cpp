#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string& s)
{
    int n = s.size();
    stack<string>st;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        string str = "";
        str += ch;

        if(isalpha(ch) || isdigit(ch))
            st.push(str);

        else
        {
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();
            string res = "(" + B + str + A + ")";
            st.push(res);
        }
    }
    
    return st.top();
}

int main()
{
    string postfix;
    cout<<"Enter the postfix expression: ";
    cin>>postfix;
    string infix = postfixToInfix(postfix);
    cout<<"The infix expression is: "<<infix<<endl;
    return 0;
}
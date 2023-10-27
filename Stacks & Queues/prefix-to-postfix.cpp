#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string& s)
{
    int n = s.size();
    stack<string>st;

    for (int i = n-1; i >= 0; i--)
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

            string res = A + B + str;
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string prefix; 
    cout<<"Enter prefix expression: ";
    cin>>prefix;
    string postfix = prefixToPostfix(prefix);
    cout<<"The postfix expression is: "<<postfix<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string& s)
{
    int n = s.size();
    stack<string>st;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        string str = "";
        str += ch;

        if(isdigit(ch) || isalpha(ch))
        {
            st.push(str);
        }

        else
        {
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();

            string res = "(" + A + str + B + ")";
            st.push(res);
        }
    }

    return st.top();
}

int main()
{
    string prefix; 
    cout<<"Enter the prefix expression: ";
    cin>>prefix;
    string infix = prefixToInfix(prefix);
    cout<<"The infix expression is: "<<infix<<endl;
    return 0;
}
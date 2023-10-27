#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string& s)
{
    int n = s.size();
    stack<string>st;

    for(int i=0; i<n; i++)
    {
        char ch = s[i];
        string str = "";
        str += ch;

        if(isalpha(ch) || isdigit(ch))
        {
            st.push(str);
        }

        else
        {
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();

            string res = str + B + A ;
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string postfix;
    cout<<"Enter postfix expression: ";
    cin>>postfix;
    string prefix = postfixToPrefix(postfix);
    cout<<"The prefix expression is: "<<prefix<<endl;
    return 0;
}
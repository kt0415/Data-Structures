#include <bits/stdc++.h> 
using namespace std;

int canYouMake(string &str, string &ptr)
{
    int n = str.size();
    int m = ptr.size();

    vector<int>prev(m+1,0),curr(m+1,0);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(str[i-1] == ptr[j-1])
                curr[j] = 1 + prev[j-1];

            else
                curr[j] = max(prev[j],curr[j-1]);
        }
        prev = curr;
    }

    int ans = n + m - 2*prev[m];
    return ans;
}
#include <bits/stdc++.h> 
using namespace std;

bool check(string &s1, string &s2)
{
    if(s1.size() - s2.size()!= 1)   return false;

    int first = 0, second = 0; 

    while(first < s1.size())
    {
        if(second<=s2.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }

        else
        {
            first++;
        }
    }

    if(first == s1.size() && second == s2.size())
        return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(),arr.end(), comp);
    vector<int>dp(n,1);
    int maxi = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(check(arr[i],arr[j]) && dp[j] + 1 > dp[i])
                dp[i] = dp[j]+1;
        }
        maxi = max(maxi,dp[i]);
    }

    return maxi;
}
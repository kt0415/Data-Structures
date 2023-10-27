#include <bits/stdc++.h> 
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int>dp(n,1),cnt(n,1);
    int maxi = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j]<arr[i] && dp[j] + 1 > dp[i])  //inherit
            {
                dp[i] = dp[j]+1;
                cnt[i] = cnt[j];
            }

            else if(arr[j]<arr[i] && dp[j] + 1 == dp[i])    //increase cnt
                cnt[i] += cnt[j];
        }
        maxi = max(maxi,dp[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] == maxi)
            ans += cnt[i];
    }

    return ans;
}
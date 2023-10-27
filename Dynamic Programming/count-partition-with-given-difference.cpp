#include <bits/stdc++.h> 
using namespace std;

int mod = (int)(1e9+7);

int solve(int idx, int s, vector<int>&arr, vector<vector<int>>&dp)
{
    if(idx == 0)
    {
        if(s == 0 && arr[0] == 0)    return 2;
        else if(arr[0] == s || s == 0)  return 1;
        return 0;
    }

    if(dp[idx][s]!= -1) return dp[idx][s];

    int notpick = solve(idx-1,s,arr,dp);
    int pick = 0;
    if(arr[idx]<=s) pick = solve(idx-1,s-arr[idx],arr,dp);

    return dp[idx][s] = (pick + notpick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    int s2 = -1;
    if(sum-d <0 || (sum-d)%2)
        return false;

    s2 = (sum-d)/2;

    vector<vector<int>>dp(n,vector<int>(s2+1,-1));

    return solve(n-1,s2,arr,dp);
}



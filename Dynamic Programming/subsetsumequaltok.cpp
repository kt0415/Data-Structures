#include <bits/stdc++.h> 
using namespace std;

//Memoization
// bool solve(int idx, int target, vector<int>&arr,vector<vector<int>>&dp)
// {
//     if(target == 0) return true;

//     if(idx == 0)    return arr[idx] == target;

//     if(dp[idx][target]!= -1)    return dp[idx][target];

//     bool notpick = solve(idx-1,target,arr,dp);

//     bool pick = 0;

//     if(target>=arr[idx])    pick = solve(idx-1,target-arr[idx],arr,dp);

//     return dp[idx][target] = pick or notpick;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) 
// {
//    vector<vector<int>>dp(n,vector<int>(k+1,-1));
//     return solve(n-1,k,arr,dp);
// }

//Tabulation TC:O(N*target) SC:O(N*target)
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0; i<n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int idx=1; idx<n; idx++)
    {
        for(int target=1; target<=k; target++)
        {
            bool notpick = dp[idx-1][target];
            bool pick = false;
            if(arr[idx]<=target)    pick = dp[idx-1][target-arr[idx]];

            dp[idx][target] = pick | notpick;
        }
    }

    return dp[n-1][k];
}
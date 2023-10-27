#include <bits/stdc++.h> 
using namespace std;

//MEMOIZATION TC:O(N*T), SC:O(N*T) + O(T)...auxillary stack space
// int solve(int idx, int T, vector<int>&nums, vector<vector<int>>&dp)
// {
//     if(idx == 0)
//     {
//         if(T%nums[0]==0)  return T/nums[0];
//         else    return 1e9;
//     }

//     if(dp[idx][T]!= -1) return dp[idx][T];

//     int skip = solve(idx-1,T,nums,dp);
//     int take = INT_MAX;
//     if(nums[idx]<=T)
//         take = 1 + solve(idx,T-nums[idx],nums,dp);

//     return dp[idx][T] = min(take,skip);
// }


// int minimumElements(vector<int> &nums, int x)
// {
//     int n = nums.size();
//     vector<vector<int>>dp(n,vector<int>(x+1,-1));

//     int ans = solve(n-1,x,nums,dp);

//     if(ans >= 1e9)  return -1;
//     return ans;
// }

//TABULATION TC:O(N*T), SC:O(N*T)
// int minimumElements(vector<int> &nums, int x)
// {
//     int n = nums.size();
//     vector<vector<int>>dp(n,vector<int>(x+1,0));

//     for(int t = 0; t<= x; t++)
//     {
//         if(t%nums[0] == 0)  dp[0][t] = t/nums[0];
//         else    dp[0][t] = 1e9;
//     }

//     for(int idx = 1; idx < n; idx++)
//     {
//         for(int tar = 0; tar <= x; tar++)
//         {
//             int skip = dp[idx-1][tar];
//             int take = INT_MAX;
//             if(nums[idx]<=tar)
//                 take = 1 + dp[idx][tar-nums[idx]];

//             dp[idx][tar] = min(take,skip);   
//         }
//     }

//     int ans = dp[n-1][x];

//     if(ans >= 1e9)  return -1;
//     return ans;
// }

//SPACE OPTIMISATION   TC:O(N*T), SC:O(2T) 
int minimumElements(vector<int> &nums, int x)
{
    int n = nums.size();
    // vector<vector<int>>dp(n,vector<int>(x+1,0));
    vector<int>prev(x+1,0),curr(x+1,0);

    for(int t = 0; t<= x; t++)
    {
        if(t%nums[0] == 0)  prev[t] = t/nums[0];
        else    prev[t] = 1e9;
    }

    for(int idx = 1; idx < n; idx++)
    {
        for(int tar = 0; tar <= x; tar++)
        {
            int skip = prev[tar];
            int take = INT_MAX;
            if(nums[idx]<=tar)
                take = 1 + curr[tar-nums[idx]];

            curr[tar] = min(take,skip);   
        }
        prev = curr;
    }

    int ans = prev[x];

    if(ans >= 1e9)  return -1;
    return ans;
}
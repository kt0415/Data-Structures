
//MEMOIZATION TC:- O(N*TAR), SC:- O(N*TAR) + O(N)
// #include <bits/stdc++.h> 
// using namespace std;

// int solve(int idx, int s, vector<int>&nums, vector<vector<int>>&dp)
// {
//     if(idx==0)
//     {
//         if(s==0 && nums[0]==0) return 2;
//         if(nums[0]==s || s==0) return 1;
//         return 0;
//     }

//     if(dp[idx][s] != -1)  return dp[idx][s];

//     int notpick = solve(idx-1,s,nums,dp);
//     int pick = 0;
//     if(nums[idx]<=s)    pick = solve(idx-1,s-nums[idx],nums,dp);

//     return dp[idx][s] = pick + notpick;   
// }

// int findWays(vector<int> &nums, int tar)
// {
//     int n = nums.size();
//     vector<vector<int>>dp(n, vector<int>(tar+1,-1));
//     return solve(n-1,tar,nums,dp);
// }

//TABULATION TC:- O(N*TAR), SC:- O(N*TAR)
#include <bits/stdc++.h> 
using namespace std;

int findWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(tar+1,0));

    for(int i=0; i<n; i++)
        dp[i][0] = 1;

    if(nums[0] == 0)    dp[0][nums[0]] = 2;
    else if(nums[0]<=tar)  dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++)
    {
        for(int s = 0; s <= tar; s++)
        {
            int notpick = dp[i-1][s];
            int pick = 0;
            if(nums[i]<=s)  pick = dp[i-1][s-nums[i]];

            dp[i][s] = pick + notpick;
        }
    } 
    
    return dp[n-1][tar];
}
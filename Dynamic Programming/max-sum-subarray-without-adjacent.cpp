#include <bits/stdc++.h> 
using namespace std;

//memoization approach .. TC: O(N) , SC: O(N) + O(N)

// int solve(int ind, vector<int>&nums, vector<int>&dp)
// {
//     if(ind <0)  return 0;

//     if(ind == 0)    return nums[ind];
//     if(dp[ind] != -1)   return dp[ind];

//     int pick = nums[ind] + solve(ind-2,nums,dp);
//     int notpick = 0 + solve(ind-1,nums,dp);

//     return dp[ind] = max(pick,notpick);
// }


// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int>dp(n+1,-1);
//     int ans = solve(n-1, nums, dp);

//     return ans;
// }

//Tabulation
// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int>dp(n,-1);
//     dp[0] = nums[0];
//     int neg = 0;

//     for(int i=1; i<n; i++)
//     {
//         int take = nums[i];
//         if(i>1) take += dp[i-2];
//         int skip = dp[i-1];

//         dp[i] = max(take,skip);
//     }

//     return dp[n-1];
// }

//Space Optimisation :-{TC,SC}:{O(N);O(1)}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0;
    for(int i=1; i<n; i++)
    {
        int take = nums[i];
        if(i>1) take += prev2;
        int skip = prev;

        int curr = max(take,skip);
        prev2 = prev;
        prev = curr; 
    }

    return prev;
}
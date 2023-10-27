#include <bits/stdc++.h>
using namespace std;

//momoization approach
// int solve(int ind, vector<int>&heights, vector<int>&dp)
// {
//     if(ind == 0)    return 0;

//     if(dp[ind]!=(-1))   return dp[ind];

//     int left = solve(ind-1,dp,heights) + abs(heights[ind] - heights[ind-1]);
//     int right = INT_MAX;
//     if(ind>1)   right = solve(ind-2,dp,heights) + abs(heights[ind] - heights[ind-2]);

//     return dp[ind] = min(left,right);
// }

// int frogjumps(int n, vector<int>&heights)
// {
//     vector<int>dp(n+1,-1);
//     return solve(n-1,heights,dp);
// }

int frogjumps2(int n, vector<int>&heights)
{
    //tabulation method
    // vector<int>dp(n, 0);
    // for (int i = 1; i < n; i++)
    // {
    //     int first = dp[i-1] + abs(heights[i] - heights[i-1]);
    //     int second = INT_MAX;
    //     if(i>1) second = dp[i-2] + abs(heights[i] - heights[i-2]);

    //     dp[i] = min(first,second);
    // }
    
    // return dp[n-1];

    //SPACE OPTIMIZATION using curr,prev,prev2
    int prev = 0, prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int first = prev + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i>1) second = prev2 + abs(heights[i] - heights[i-2]);

        int curr = min(first,second);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}

int main()
{
    int n; cin>>n;
    vector<int>heights(n);
    for(int i=0; i<n; i++)
        cin>>heights[i];

    int ans = frogjumps2(n,heights);
    cout<<ans<<endl;
    return 0;
}
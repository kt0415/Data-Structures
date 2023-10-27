//MEMOIZATION TC:O(N*W) SC:O(N*W) + O(W)
// #include <bits/stdc++.h> 
// using namespace std;

// int solve(int ind, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp)
// {
//     if(ind == 0)
//         return W/wt[0] * val[0];

//     if(dp[ind][W] != -1)    return dp[ind][W];

//     int skip = solve(ind-1,W,val,wt,dp);
//     int take = INT_MIN;
//     if(wt[ind]<=W)  take = val[ind]  + solve(ind,W-wt[ind],val,wt,dp);

//     return dp[ind][W] = max(take,skip);
// }

// int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
// {
//     vector<vector<int>>dp(n, vector<int>(w+1,-1));
//     return solve(n-1,w,val,wt,dp);
// }

//TABULATION    TC:O(N*W) SC:O(N*W) 
// #include <bits/stdc++.h> 
// using namespace std;

// int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
// {
//     vector<vector<int>>dp(n, vector<int>(W+1,0));
    
//     //Base Case
//     for(int i = 0; i<=W; i++)
//     {
//         dp[0][i] = i/wt[0]*val[0];
//     }

//     //Nested Loops
//     for(int ind=1; ind<n; ind++)
//     {
//         for(int cap = 0; cap<=W; cap++)
//         {
//             int skip = dp[ind-1][cap];
//             int take = INT_MIN;
//             if(wt[ind]<=cap)  take = val[ind] + dp[ind][cap-wt[ind]];

//             dp[ind][cap] = max(take,skip);
//         }
//     }

//     return dp[n-1][W];
// }

//SPACE OPTIMISATION    TC:O(N*W) SC:O(W) + O(W)
// #include <bits/stdc++.h> 
// using namespace std;

// int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
// {
//     vector<vector<int>>dp(n, vector<int>(W+1,0));
//     vector<int>prev(W+1,0),curr(W+1,0);
    
//     //Base Case
//     for(int i = 0; i<=W; i++)
//     {
//         prev[i] = i/wt[0]*val[0];
//     }

//     //Nested Loops
//     for(int ind=1; ind<n; ind++)
//     {
//         for(int cap = 0; cap<=W; cap++)
//         {
//             int skip = prev[cap];
//             int take = INT_MIN;
//             if(wt[ind]<=cap)  take = val[ind] + curr[cap-wt[ind]];

//             curr[cap] = max(take,skip);
//         }
//         prev = curr;
//     }

//     return prev[W];
// }

//ULTIMATE OPTIMISATION     TC:O(N*W) SC:O(W)
#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n, vector<int>(W+1,0));
    vector<int>prev(W+1,0);
    
    //Base Case
    for(int i = 0; i<=W; i++)
    {
        prev[i] = i/wt[0]*val[0];
    }

    //Nested Loops
    for(int ind=n-1; ind>=0; ind--)
    {
        for(int cap = 0; cap<=W; cap++)
        {
            int skip = prev[cap];
            int take = INT_MIN;
            if(wt[ind]<=cap)  take = val[ind] + prev[cap-wt[ind]];

            prev[cap] = max(take,skip);
        }
    }

    return prev[W];
}



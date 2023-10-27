//MEMOIZATION TC:O(N*2) SC:O(N*2) + O(N) ..aux st space
// #include<bits/stdc++.h>
// using namespace std;

// long solve(int ind, int buy, long *values, int n, vector<vector<long>>&dp)
// {
//     if(ind == n)    return 0;   //base case

//     if(dp[ind][buy]!= -1)   return dp[ind][buy];    //overlapping subproblems
    
//     long profit = 0;
//     if(buy)
//     {
//         profit = max((-values[ind] + solve(ind+1, 0, values, n, dp)),solve(ind+1,1,values,n,dp));   
//     }

//     else
//     {
//         profit = max((values[ind] + solve(ind+1,1,values,n,dp)), solve(ind+1,0,values,n,dp));
//     }

//     return dp[ind][buy] = profit;
// }

// long getMaximumProfit(long *values, int n)
// {
//     vector<vector<long>>dp(n,vector<long>(2,-1));
//     return solve(0,1,values,n,dp);
// }

//TABULATION    TC:O(N*2) SC:O(N*2)
// #include<bits/stdc++.h>
// using namespace std;

// long solve(int ind, int buy, long *values, int n, vector<vector<long>>&dp)
// {
//     if(ind == n)    return 0;   //base case

//     if(dp[ind][buy]!= -1)   return dp[ind][buy];    //overlapping subproblems
    
//     long profit = 0;
//     if(buy)
//     {
//         profit = max((-values[ind] + solve(ind+1, 0, values, n, dp)),solve(ind+1,1,values,n,dp));   
//     }

//     else
//     {
//         profit = max((values[ind] + solve(ind+1,1,values,n,dp)), solve(ind+1,0,values,n,dp));
//     }

//     return dp[ind][buy] = profit;
// }

// long getMaximumProfit(long *values, int n)
// {
//     vector<vector<long>>dp(n+1,vector<long>(2,0));
//     dp[n][0] = 0, dp[n][1] = 0;
//     for(int ind = n-1; ind >= 0; ind--)
//     {
//         for(int buy=0; buy<2; buy++)
//         {
//             long profit = 0;
//             if(buy)
//             {
//                 profit = max((-values[ind] + dp[ind+1][0]),dp[ind+1][1]);   
//             }

//             else
//             {
//                 profit = max((values[ind] + dp[ind+1][1]),dp[ind+1][0]);
//             }

//             dp[ind][buy] = profit;
//         }
//     }

//     return dp[0][1];
// }

//SPACE OPTIMISATION    TC:O(N*2) SC:O(2) + O(2)
#include<bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n)
{
    vector<long>ahead(2,0), curr(2,0);
    // ahead[0] = 0, ahead[1] = 0; //omit-able base case
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy=0; buy<2; buy++)
        {
            long profit = 0;
            if(buy)
            {
                profit = max((-values[ind] + ahead[0]),ahead[1]);   
            }

            else
            {
                profit = max((values[ind] + ahead[1]),ahead[0]);
            }

            curr[buy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];
}
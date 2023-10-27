//MEMOIZATION   //TC:O(N*2) SC:O(N*2) + O(N)..aux st space
// #include <bits/stdc++.h> 
// using namespace std;

// int solve(int ind, int buy, vector<int>&prices, int n, int fee, vector<vector<int>>&dp)
// {
//     //base case
//     if(ind == n)    return 0;

//     //overlapping subproblems
//     if(dp[ind][buy] != -1)  return dp[ind][buy];

//     //possibilities
//     int profit = 0;
//     if(buy)
//     {
//         profit = max(-prices[ind] + solve(ind+1,0,prices,n,fee,dp), solve(ind+1,1,prices,n,fee,dp));
//     }

//     else
//     {
//         profit = max(prices[ind] - fee + solve(ind+1,1,prices,n,fee,dp) , solve(ind+1,0,prices,n,fee,dp));
//     }

//     return dp[ind][buy] = profit;
// }

// int maximumProfit(int n, int fee, vector<int> &prices) {
//     vector<vector<int>>dp(n,vector<int>(2,-1));

//     return solve(0,1,prices,n,fee,dp);
// }

//TABULATION    TC:O(N*2) SC:O(N*2)
// #include <bits/stdc++.h> 
// using namespace std;

// int maximumProfit(int n, int fee, vector<int> &prices) {
//     vector<vector<int>>dp(n+1,vector<int>(2,0));

//     for(int ind = n-1; ind >=0; ind --)
//     {
//         for(int buy = 0; buy < 2; buy ++)
//         {
//             int profit = 0;
//             if(buy)
//             {
//                 profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
//             }

//             else
//             {
//                 profit = max(prices[ind] - fee + dp[ind+1][1], dp[ind+1][0]);
//             }

//             dp[ind][buy] = profit;
//         }
//     }

//     return dp[0][1];
// }

//SPACE OPTIMISATION    TC:O(N*2) SC:O(2) + O(2)   
#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<int>ahead(2,0),curr(2,0);

    for(int ind = n-1; ind >=0; ind --)
    {
        for(int buy = 0; buy < 2; buy ++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max(-prices[ind] + ahead[0], ahead[1]);
            }

            else
            {
                profit = max(prices[ind] - fee + ahead[1], ahead[0]);
            }

            curr[buy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];
}

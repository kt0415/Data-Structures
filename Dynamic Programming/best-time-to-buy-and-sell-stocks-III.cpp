//MEMOIZATION TC:O(N*2*3) SC:O(N*2*3) + O(N) .. aux st space
// #include <bits/stdc++.h> 
// using namespace std;

// int solve(int ind, int buy, int cap, vector<int>&prices, int n, vector<vector<vector<int>>>&dp)
// {
//     if(ind == n || cap == 0)    return 0;   //base case

//     if(dp[ind][buy][cap]!= -1)  return dp[ind][buy][cap];   //overlapping subproblems

//     int profit = 0;
//     if(buy)
//     {
//         profit = max((-prices[ind] + solve(ind+1,0,cap,prices,n,dp)), (0 + solve(ind+1,1,cap,prices,n,dp)));
//     }

//     else
//     {
//         profit = max((prices[ind] + solve(ind+1,1,cap-1,prices,n,dp)), (0 + solve(ind+1,0,cap,prices,n,dp)));
//     }

//     return dp[ind][buy][cap] = profit;
// }

// int maxProfit(vector<int> &prices, int n) {
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//     return solve(0,1,2,prices,n,dp);
// }

//TABULATION    TC:O(N*2*3) SC:O(N*2*3)
// #include <bits/stdc++.h> 
// using namespace std;

// int maxProfit(vector<int> &prices, int n) {
//     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

//     //base cases
//     for(int ind = 0; ind <=n ; ind++)
//     {
//         for(int buy = 0; buy <2; buy ++)
//         {
//             dp[ind][buy][0] = 0;
//         }
//     }

//     for(int buy=0; buy < 2; buy ++)
//     {
//         for(int cap=0; cap < 3; cap++)
//         {
//             dp[n][buy][cap] = 0;
//         }
//     }

//     //nested loops for changing parameters
//     for(int ind = n-1; ind >= 0; ind --)
//     {
//         for(int buy = 0; buy < 2; buy ++)
//         {
//             for(int cap = 2; cap > 0; cap --)
//             {
//                 int profit = 0;
//                 if(buy)
//                 {
//                     profit = max((-prices[ind] + dp[ind+1][0][cap]),dp[ind+1][1][cap]);
//                 }

//                 else
//                 {
//                     profit = max((prices[ind] +dp[ind+1][1][cap-1]),dp[ind+1][0][cap]);
//                 }

//                 dp[ind][buy][cap] = profit;
//             }
//         }
//     }

//     return dp[0][1][2];
// }

//SPACE OPTIMIZATION    TC:O(N*2*3) SC:O(2*3) + O(2*3)
#include <bits/stdc++.h> 
using namespace std;

int maxProfit(vector<int> &prices, int n) {
    vector<vector<int>>ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
    //base cases not needed as all initialised to zero

    //nested loops for changing parameters
    for(int ind = n-1; ind >= 0; ind --)
    {
        for(int buy = 0; buy < 2; buy ++)
        {
            for(int cap = 2; cap > 0; cap --)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max((-prices[ind] + ahead[0][cap]),ahead[1][cap]);
                }

                else
                {
                    profit = max((prices[ind] +ahead[1][cap-1]),ahead[0][cap]);
                }

                curr[buy][cap] = profit;
            }
        }
        ahead = curr;
    }

    return ahead[1][2];
}
//MEMOIZATION   TC:O(M^3) SC:O(M^2) + O(M)..aux st space .. M is cut array ka size
// #include <bits/stdc++.h> 
// using namespace std;

// int solve(int i, int j, vector<int>&cuts,vector<vector<int>>&dp)
// {
//     if(i>j) return 0;

//     if(dp[i][j] != -1)  return dp[i][j];

//     int mini = INT_MAX;

//     for(int k=i; k<=j; k++)
//     {
//         int cost = cuts[j+1] - cuts[i-1] + solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp);
//         mini = min(mini,cost);
//     }

//     return dp[i][j] = mini;
// }

// int cost(int n, int c, vector<int> &cuts)
// {
//     sort(cuts.begin(),cuts.end());
//     cuts.push_back(n);
//     cuts.insert(cuts.begin(), 0);
//     vector<vector<int>>dp(c+1,vector<int>(c+1,-1));

//     return solve(1,c,cuts,dp);
// }

//TABULATION    TC:O(M^3) SC:O(M^2)
#include <bits/stdc++.h> 
using namespace std;

int cost(int n, int c, vector<int> &cuts)
{
    sort(cuts.begin(),cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>>dp(c+2,vector<int>(c+2,0));

    for(int i=c; i>0; i--)
    {
        for(int j=1; j<=c; j++)
        {
            if(i>j) continue;

            int mini = INT_MAX;

            for(int k=i; k<=j; k++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini,cost);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}
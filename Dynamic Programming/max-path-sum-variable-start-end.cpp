#include <bits/stdc++.h> 
using namespace std;

//Memoization TC: O(N*M), SC: O(N*M) + O(N) recursive stack space
// int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     if(j<0 || j>m-1)
//         return -1e9;

//     if(i == 0)
//         return matrix[0][j];

//     if(dp[i][j]!=(-1))  return dp[i][j];

//     int up = matrix[i][j] + solve(i-1,j,matrix,dp);
//     int leftup = matrix[i][j] + solve(i-1,j-1,matrix,dp);
//     int rightup = matrix[i][j] + solve(i-1,j+1,matrix,dp); 

//     return dp[i][j] = max(up,max(leftup,rightup));
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     int ans = INT_MIN;
//     for(int k = 0; k < m; k++)
//     {
//         ans = max(ans,solve(n-1,k,matrix,dp));   
//     }

//     return ans;
// }

//Tabulation
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     vector<vector<int>>dp(n,vector<int>(m,0));
//     for(int j = 0; j < m; j++)
//     {
//         dp[0][j] = matrix[0][j];
//     }

//     for(int i=1; i<n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             int up = matrix[i][j] + dp[i-1][j];
//             int left = matrix[i][j];
//             if(j>=1) left += dp[i-1][j-1];
//             else    left += -1e8;
//             int right = matrix[i][j];
//             if(j<m-1) right += dp[i-1][j+1];
//             else    right += -1e8;
//             dp[i][j] = max(up,max(left,right));
//         }
//     }

//     int ans = INT_MIN;
//     for(int j=0; j<m; j++)
//     {
//         ans = max(ans,dp[n-1][j]);
//     }

//     return ans;
// }

//Space Optimization
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int>prev(m,0);
    vector<int>curr(m,0);
    for(int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for(int i=1; i<n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];
            int left = matrix[i][j];
            if(j>=1) left += prev[j-1];
            else    left += -1e8;
            int right = matrix[i][j];
            if(j<m-1) right += prev[j+1];
            else    right += -1e8;
            curr[j] = max(up,max(left,right));
        }

        prev = curr;
    }

    int ans = INT_MIN;
    for(int j=0; j<m; j++)
    {
        ans = max(ans,prev[j]);
    }

    return ans;
}
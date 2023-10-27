#include <bits/stdc++.h> 
using namespace std;

//MEMOIZATION

// int solve(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&dp)
// {
//     if(row==0 && col==0)    return grid[row][col];

//     if(row<0 || col<0)  return 1e9;

//     if(dp[row][col]!=-1)    return dp[row][col];

//     int up = grid[row][col] + solve(grid,row-1,col,dp);
//     int left = grid[row][col] + solve(grid,row,col-1,dp);

//     return dp[row][col] = min(up,left);
// }

// int minSumPath(vector<vector<int>> &grid) 
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     return solve(grid,n-1,m-1,dp);
// }

//TABULATION

// #include <bits/stdc++.h> 
// int minSumPath(vector<vector<int>> &grid) 
// {
//     int n = grid.size();
//     int m = grid[0].size();

//     vector<vector<int>>dp(n,vector<int>(m,0));

//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             if(i==0 && j==0)    dp[i][j] = grid[i][j];

//             else
//             {
//                 int up = grid[i][j];
//                 int left = grid[i][j];

//                 if(i>0) up += dp[i-1][j];
//                 else    up += 1e9;
//                 if(j>0) left += dp[i][j-1];
//                 else    left += 1e9;
//                 dp[i][j] = min(up,left);
//             }
//         }
//     }

//     return dp[n-1][m-1];
// }
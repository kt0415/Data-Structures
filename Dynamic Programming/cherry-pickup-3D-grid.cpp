//MEMOIZATION
#include <bits/stdc++.h> 
using namespace std;

int solve(int i, int j1, int j2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp)
{
    int n = grid.size();
    int m = grid[0].size();

    if(j1<0 || j1>=m || j2<0 || j2>=m)  return -1e8;

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    if(i == n - 1)
    {
        if(j1 == j2)    return grid[i][j1];
        else    return grid[i][j1] + grid[i][j2];
    }

    int val = INT_MIN;
    for(int dj1=-1; dj1<=1; dj1++)
    {
        for(int dj2=-1; dj2<=1; dj2++)
        {
            int value = 0;
            if(j1 == j2)
                value = grid[i][j1]+solve(i+1,j1+dj1,j2+dj2,grid,dp);

            else
                value = grid[i][j1]+grid[i][j2]+solve(i+1,j1+dj1,j2+dj2,grid,dp);

            val = max(val,value);
        }
    }

    return dp[i][j1][j2] = val;
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return solve(0,0,c-1,grid,dp);
}
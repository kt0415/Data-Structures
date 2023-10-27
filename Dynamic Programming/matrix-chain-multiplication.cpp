//MEMOIZATION: TC: O(N**3) SC: O(N**2) + O(N)..aux st space

// #include <bits/stdc++.h>
// using namespace std; 

// int solve(int i, int j, vector<int>&arr, vector<vector<int>>&dp)
// {
//     if(i == j)  return 0;   //base case

//     if(dp[i][j] != -1)  return dp[i][j];
    
//     int mini = INT_MAX;
//     for(int k = i; k < j; k++)  //looping
//     {   
//         int steps = arr[i-1] * arr[k] * arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
//         mini = min(mini,steps);
//     }

//     return dp[i][j] = mini;
// }

// int matrixMultiplication(vector<int> &arr, int n)
// {
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     return solve(1, n-1, arr,dp);
// }

//TABULATION    TC: O(N**3) SC: O(N**2)
#include <bits/stdc++.h>
using namespace std; 

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>>dp(n,vector<int>(n,0));

    //base case not reqd to be updated as all dp elements are initialised to 0 themselves
    for(int i=n-1; i>0; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            int mini = INT_MAX;
            for(int k = i; k < j; k++)  //looping
            {   
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,steps);
            }

            dp[i][j] = mini;
        }
    }
    
    return dp[1][n-1];
}
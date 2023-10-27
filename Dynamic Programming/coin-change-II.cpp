#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION TC:O(N*T), SC:O(N*T) + O(T)
// long solve(int ind, int t, int *arr, vector<vector<long>>&dp)
// {
//     if(ind == 0)
//     {
//         if(t%arr[0] == 0)  return 1;
//         else return 0;
//     }

//     if(dp[ind][t]!= -1) return dp[ind][t];

//     long skip = solve(ind-1,t,arr,dp);
//     long take = 0;
//     if(arr[ind]<=t) take = solve(ind,t-arr[ind],arr,dp);

//     return dp[ind][t] = skip + take;
// }

// long countWaysToMakeChange(int *denominations, int n, int value)
// {
//     vector<vector<long>>dp(n,vector<long>(value+1,-1));
//     return solve(n-1,value,denominations,dp);
// }

//TABULATION    TC:O(N*T), SC:O(N*T)
// #include<bits/stdc++.h>
// using namespace std;

// long countWaysToMakeChange(int *den, int n, int value)
// {
//     vector<vector<long>>dp(n,vector<long>(value+1,0));
    
//     for(int i=0; i<=value; i++)  dp[0][i] = (i%den[0]==0);

//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int tar = 0; tar <= value; tar++)
//         {
//             long skip = dp[ind-1][tar];
//             long take = 0;
//             if(den[ind]<=tar) take = dp[ind][tar-den[ind]];

//             dp[ind][tar] = skip + take;   
//         }
//     }
    
//     return dp[n-1][value];

// }

//SPACE OPTIMISATION    TC:O(N*T), SC:O(T) + O(T)
#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *den, int n, int value)
{
    vector<long>prev(value+1,0),curr(value+1,0);
    
    for(int i=0; i<=value; i++)  prev[i] = (i%den[0]==0);

    for(int ind = 1; ind < n; ind++)
    {
        for(int tar = 0; tar <= value; tar++)
        {
            long skip = prev[tar];
            long take = 0;
            if(den[ind]<=tar) take = curr[tar-den[ind]];

            curr[tar] = skip + take;   
        }
        prev = curr;
    }
    
    return prev[value];
}
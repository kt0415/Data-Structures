//MEMOIZATION TC: O(N*N) SC:O(N*N) + O(N) ..aux st space
// #include<bits/stdc++.h>
// using namespace std;

// int solve(int idx, int prev, int arr[], int n, vector<vector<int>>&dp)
// {
//     if(idx == n)    return 0;   //base case

//     if(dp[idx][prev+1] != -1)   return dp[idx][prev+1]; //overlapping subproblems elimination

//     int len1 = 0 + solve(idx+1,prev,arr,n,dp);  //not pick
//     int len2 = 0;
//     if(prev == -1 || arr[idx]>arr[prev])
//         len2 = 1 + solve(idx+1,idx,arr,n,dp);   //pick

//     int len = max(len1,len2);   //LIS

//     return dp[idx][prev+1] = len;
// }

// int longestIncreasingSubsequence(int arr[], int n)
// {
//     vector<vector<int>>dp(n,vector<int>(n+1,-1));

//     return solve(0,-1,arr,n,dp);
// }

//TABULATION    TC: O(N*N) SC:O(N*N)
// #include<bits/stdc++.h>
// using namespace std;

// int longestIncreasingSubsequence(int arr[], int n)
// {
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

//     for(int ind = n-1; ind>=0; ind--)
//     {
//         for(int prev = ind-1; prev>=-1; prev--)
//         {
//             int len1 = 0 + dp[ind+1][prev+1]; //not pick
//             int len2 = 0;
//             if(prev == -1 || arr[ind]>arr[prev])
//                 len2 = 1 + dp[ind+1][ind+1];   //pick

//             int len = max(len1,len2);   //LIS

//             dp[ind][prev+1] = len;
//         }
//     }

//     return dp[0][0];
// }

//SPACE OPTIMISATION    TC: O(N*N) SC:O(N)+O(N)
// #include<bits/stdc++.h>
// using namespace std;

// int longestIncreasingSubsequence(int arr[], int n)
// {
//     // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     vector<int>next(n+1,0),curr(n+1,0);
//     for(int ind = n-1; ind>=0; ind--)
//     {
//         for(int prev = ind-1; prev>=-1; prev--)
//         {
//             int len1 = 0 + next[prev+1]; //not pick
//             int len2 = 0;
//             if(prev == -1 || arr[ind]>arr[prev])
//                 len2 = 1 + next[ind+1];   //pick

//             int len = max(len1,len2);   //LIS

//             curr[prev+1] = len;
//         }
//         next = curr;
//     }

//     return next[0];
// }


//MOST OPTIMAL SOLUTION..necessary to traceback the LIS    TC: O(N*N) SC:O(N)
// #include<bits/stdc++.h>
// using namespace std;

// int longestIncreasingSubsequence(int arr[], int n)
// {
//     vector<int>dp(n,1);
//     int maxi = 1;
//     for(int ind=0; ind<n; ind++)
//     {
//         for(int prev=0; prev<ind; prev++)
//         {
//             if(arr[prev]<arr[ind])
//                 dp[ind] = max(dp[ind], dp[prev]+1);
//         }
//         maxi = max(maxi,dp[ind]);
//     }

//     return maxi;
// }

//PRINTING THE LIS:-    
#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1),hash(n+1);
    int maxi = 1, last = 0;
    for(int ind=0; ind<n; ind++)
    {
        hash[ind] = ind;
        for(int prev=0; prev<ind; prev++)
        {
            if(arr[prev]<arr[ind] && dp[prev]+1>dp[ind])
                dp[ind] = dp[prev]+1;
                hash[ind] = prev;
        }
        if(dp[ind]>maxi)
        {
            maxi = dp[ind];
            last = ind;
        }
    }

    vector<int>lis;
    while(hash[last]!=last)
    {
        last = hash[last];
        lis.push_back(arr[last]);
    }

    cout<<"The Longest Increasing Subsequence is :- ";
    for(auto it: lis)   cout<<it<<" ";
    cout<<endl;

    return maxi;
}

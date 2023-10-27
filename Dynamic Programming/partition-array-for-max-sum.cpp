//MEMOIZATION TC: O(N)*O(K) SC:O(N) + O(N)..aux st space

// class Solution {
// public:
//     int solve(int ind, vector<int>&arr, int n, int k, vector<int>&dp)
//     {
//         if(ind == n)   return 0;

//         if(dp[ind]!= -1)    return dp[ind];

//         int maxans = 0;
//         int len = 0, maxi = INT_MIN;

//         for(int j = ind; j<min(n,ind+k); j++)
//         {
//             len++;
//             maxi = max(maxi, arr[j]);
//             int sum = (len*maxi) + solve(j+1,arr,n,k,dp);
//             maxans = max(maxans, sum);
//         }

//         return dp[ind] = maxans;
//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) 
//     {
//         int n = arr.size();
//         vector<int>dp(n,-1);
//         return solve(0,arr,n,k,dp);    
//     }
// };

//TABULATION    TC: O(N)*O(K) SC:O(N)
// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) 
//     {
//         int n = arr.size();
//         vector<int>dp(n+1,0);

//         for(int ind = n-1; ind >= 0; ind --)
//         {
//             int maxans = 0;
//             int len = 0, maxi = INT_MIN;

//             for(int j = ind; j<min(n,ind+k); j++)
//             {
//                 len++;
//                 maxi = max(maxi, arr[j]);
//                 int sum = (len*maxi) + dp[j+1];
//                 maxans = max(maxans, sum);
//             }

//             dp[ind] = maxans;
//         }

//         return dp[0];    
//     }
// };
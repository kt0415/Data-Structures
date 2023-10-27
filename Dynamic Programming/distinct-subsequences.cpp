#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION   TC:O(N*M) , SC:O(N*M) + O(N+M)
// class Solution {
// private:
//     int solve(int i, int j, string s, string t, vector<vector<int>>&dp)
//     {
//         //base cases
//         if(j < 0)   return 1;
//         if(i < 0)   return 0;

//         //overlapping subproblems la eliminate kra
//         if(dp[i][j]!= -1)   return dp[i][j];

//         //if its a match .. we can pick or skip
//         if(s[i] == t[j])
//             return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);

//         else    //nsel tr move back in string s
//             return dp[i][j] = solve(i-1,j,s,t,dp);
//     }

// public:
//     int numDistinct(string s, string t) 
//     {
//         int n = s.size();
//         int m = t.size();

//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,s,t,dp);    
//     }
// };

//TABULATION    TC:O(N*M) , SC:O(N*M)
// class Solution {
// public:
//     int numDistinct(string s, string t) 
//     {
//         int n = s.size();
//         int m = t.size();

//         vector<vector<double>>dp(n+1,vector<double>(m+1,0));
//         for(int i=0; i<=n; i++) dp[i][0] = 1;

//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=m; j++)
//             {
//                 if(s[i-1] == t[j-1])
//                     dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];

//                 else    
//                     dp[i][j] = dp[i-1][j];
//             }
//         }
//         return (int)dp[n][m];    
//     }
// };

//SPACE OPTIMISATION    TC:O(N*M) , SC:O(M) + O(M)
// class Solution {
// public:
//     int numDistinct(string s, string t) 
//     {
//         int n = s.size();
//         int m = t.size();
        
//         vector<double>prev(m+1,0),curr(m+1,0);
        
//         //base case
//         prev[0] = curr[0] = 1;

//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=m; j++)
//             {
//                 if(s[i-1] == t[j-1])
//                     curr[j] = prev[j-1]+ prev[j];

//                 else    
//                     curr[j] = prev[j];
//             }
//             prev = curr;
//         }
//         return (int)prev[m];    
//     }
// };

//ULTIMATE SPACE OPTIMISATION   TC:O(N*M) , SC:O(M)
class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();

        vector<double>prev(m+1,0);
        
        //base case
        prev[0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=1; j--)
            {
                if(s[i-1] == t[j-1])
                    prev[j] = prev[j-1]+ prev[j];
            }
        }
        return (int)prev[m];    
    }
};

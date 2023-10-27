#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION   TC:- O(N*M) SC:-O(N*M) + O(N+M)..aux st space
// class Solution {
// private:
//     int solve(int i, int j, string&s1, string&s2, vector<vector<int>>&dp)
//     {
//         //base cases
//         if(i<0) return j+1;
//         if(j<0) return i+1;

//         //overlapping subproblems 
//         if(dp[i][j]!= -1)   return dp[i][j];

//         //if it is a match
//         if(s1[i] == s2[j])
//             return dp[i][j] = solve(i-1,j-1,s1,s2,dp);

//         int insertion = 1 + solve(i,j-1,s1,s2,dp);
//         int deletion = 1 + solve(i-1,j,s1,s2,dp);
//         int replacing = 1 + solve(i-1,j-1,s1,s2,dp);

//         return dp[i][j] = min(insertion,min(deletion,replacing));
//     }

// public:
//     int minDistance(string word1, string word2) 
//     {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>>dp(n, vector<int>(m,-1));
//         return solve(n-1,m-1,word1,word2,dp);    
//     }
// };

//TABULATION    TC:- O(N*M) SC:-O(N*M)
// class Solution {
// public:
//     int minDistance(string word1, string word2) 
//     {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        
//         for(int i=0; i<=n; i++) dp[i][0] = i;
//         for(int j=1; j<=m; j++) dp[0][j] = j;

//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=m; j++)
//             {
//                 if(word1[i-1] == word2[j-1])
//                     dp[i][j] = dp[i-1][j-1];
                
//                 else
//                     dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
//             }
//         }

//         return dp[n][m];    
//     }
// };

//SPACE OPTIMISATION   TC:- O(N*M) SC:-O(M) + O(M)
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();

        vector<int>prev(m+1,0),curr(m+1,0);

        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++)
        {
            curr[0] = i;
            for(int j=1; j<=m; j++)
            {
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                
                else
                    curr[j] = 1 + min(curr[j-1],min(prev[j],prev[j-1]));
            }
            prev = curr;
        }

        return prev[m];    
    }
};
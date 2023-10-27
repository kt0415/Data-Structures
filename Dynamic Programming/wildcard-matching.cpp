// MEMOIZATION TC:- O(N*M) SC:-O(N*M) + O(N+M)

#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string&s1, string&s2, vector<vector<int>>&dp)
{
   //base cases
   if(i<0 && j<0)    return true;
   if(i<0 && j>=0)   return false;

   if(j<0 && i>=0)
   {
      for(int k=0; k<=i; k++)
      {
         if(s1[k] != '*')
            return false;
      }
      return true;
   }

   //memoize
   if(dp[i][j]!= -1)    return dp[i][j];

   //if matched
   if(s1[i] == s2[j] || s1[i] == '?')
      return dp[i][j] = solve(i-1,j-1,s1,s2,dp); 

   if(s1[i] == '*')
      return dp[i][j] = solve(i-1,j,s1,s2,dp) | solve(i,j-1,s1,s2,dp);

   return dp[i][j] = false;
}

bool wildcardMatching(string s1, string s2)
{
   int n = s1.size();
   int m = s2.size();

   vector<vector<int>>dp(n,vector<int>(m,-1));
   return solve(n-1,m-1,s1,s2,dp);
}

//TABULATION    TC:- O(N*M) SC:-O(N*M)
// #include<bits/stdc++.h>
// using namespace std;

// bool wildcardMatching(string s1, string s2)
// {
//    int n = s1.size();
//    int m = s2.size();

//    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));

//    //base case
//    dp[0][0] = true;
//    for(int j=1; j<=m; j++) dp[0][j] = false;

//    for(int i=1; i<=n; i++)
//    {
//       bool flag = true;
//       for(int k=1; k<=i; k++)
//       {
//          if(s1[k-1] != '*')
//          {
//             flag = false;
//             break;
//          }
//       }
//       dp[i][0] = flag;
//    }

//    for(int i=1; i<=n; i++)
//    {
//       for(int j=1; j<=m; j++)
//       {
//          if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
//             dp[i][j] = dp[i-1][j-1]; 

//          else if(s1[i-1] == '*')
//             dp[i][j] = dp[i-1][j] | dp[i][j-1];

//          else  dp[i][j] = false;
//       }
//    }

//    return dp[n][m];
// }

//SPACE OPTIMISATION    TC:- O(N*M) SC:-O(M) + O(M)
// #include<bits/stdc++.h>
// using namespace std;

// bool wildcardMatching(string s1, string s2)
// {
//    int n = s1.size();
//    int m = s2.size();

//    vector<bool>prev(m+1,false),curr(m+1,false);

//    //base case
//    prev[0] = true;
//    for(int j=1; j<=m; j++) prev[j] = false;

//    for(int i=1; i<=n; i++)
//    {
//       bool flag = true;
//       for(int k=1; k<=i; k++)
//       {
//          if(s1[k-1] != '*')
//          {
//             flag = false;
//             break;
//          }
//       }
//       curr[0] = flag;

//       for(int j=1; j<=m; j++)
//       {
//          if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
//             curr[j] = prev[j-1]; 

//          else if(s1[i-1] == '*')
//             curr[j] = prev[j] | curr[j-1];

//          else  curr[j] = false;
//       }

//       prev = curr;
//    }

//    return prev[m];
// }

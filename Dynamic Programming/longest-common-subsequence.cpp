//MEMOIZATION TC:- O(N*M), SC:- O(N*M) + O(N+M)..auxillary stack space

// #include<bits/stdc++.h>
// using namespace std;

// int solve(int idx1, int idx2, string s, string t, vector<vector<int>>&dp)
// {
// 	if(idx1 < 0 || idx2 < 0)	return 0;	//base case

// 	if(dp[idx1][idx2]!= -1)	return dp[idx1][idx2];	//overlapping subproblems to hatao..#memoization

// 	if(s[idx1] == t[idx2])	//if char at idx1 of s matches char at idx2 of t
// 		return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, s,t,dp);

// 	else
// 		return dp[idx1][idx2] = max(solve(idx1-1,idx2,s,t,dp), solve(idx1,idx2-1,s,t,dp));
// }

// int lcs(string s, string t)
// {
// 	int n = s.size();
// 	int m = t.size();

// 	vector<vector<int>>dp(n,vector<int>(m,-1));
// 	return solve(n-1,m-1,s,t,dp);
// }

//TABULATION   TC:- O(N*M), SC:- O(N*M) 
// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string s, string t)
// {
// 	int n = s.size();
// 	int m = t.size();

// 	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

// 	for(int i=0; i<=n; i++)	dp[i][0] = 0;
// 	for(int j=0; j<=m; j++)	dp[0][j] = 0;

// 	for(int i=1; i<=n; i++)
// 	{
// 		for(int j=1; j<=m; j++)
// 		{
// 			if(s[i-1] == t[j-1])
// 				dp[i][j] = 1 + dp[i-1][j-1];

// 			else
// 				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
// 		}
// 	}

// 	return dp[n][m];
// }

//SPACE OPTIMISATION    TC:- O(N*M), SC:- O(M) + O(M)
#include<bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();

	vector<int>prev(m+1,0),curr(m+1,0);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(s[i-1] == t[j-1])
				curr[j] = 1 + prev[j-1];

			else
				curr[j] = max(prev[j],curr[j-1]);
		}
		prev = curr;
	}

	return prev[m];
}
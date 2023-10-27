 #include <bits/stdc++.h> 
 using namespace std;
 
int solve(vector<vector<int>>&triangle, int n, int i, int j, vector<vector<int>>&dp)
{
	if(i == n-1)	return triangle[n-1][j];

	if(dp[i][j]!=(-1))	return dp[i][j];

	int down = triangle[i][j] + solve(triangle, n, i+1, j, dp);
	int diag = triangle[i][j] + solve(triangle, n, i+1, j+1, dp);

	return dp[i][j] = min(down,diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return solve(triangle,n,0,0,dp);
}
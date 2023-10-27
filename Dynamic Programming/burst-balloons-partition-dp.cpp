//MEMOIZATION   TC:O(N^3) SC:O(N^2) + O(N)..aux st space
// #include <bits/stdc++.h> 
// using namespace std;

// int solve(int i, int j, vector<int>&a, vector<vector<int>>&dp)
// {
// 	if(i>j)	return 0;	//base condition

// 	if(dp[i][j] != -1)	return dp[i][j];

// 	int maxi = INT_MIN;
// 	for(int ind = i; ind <=j; ind++)
// 	{
// 		int coins = a[i-1]*a[ind]*a[j+1] + solve(i,ind-1,a,dp) + solve(ind+1,j,a,dp); 
// 		maxi = max(maxi,coins);
// 	}

// 	return dp[i][j] = maxi;
// }

// int maxCoins(vector<int>& a)
// {
// 	int n = a.size();
// 	a.push_back(1);
// 	a.insert(a.begin(),1);
// 	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
// 	return solve(1,n,a,dp);
// }

//TABULATION    TC:O(N^3) SC:O(N^2)
#include <bits/stdc++.h> 
using namespace std;

int maxCoins(vector<int>& a)
{
	int n = a.size();
	a.push_back(1);
	a.insert(a.begin(),1);
	vector<vector<int>>dp(n+2,vector<int>(n+2,0));

	for(int i=n; i>0; i--)
	{
		for(int j=1; j<=n; j++)
		{
			if(i>j)	continue;

			int maxi = INT_MIN;
			for(int ind = i; ind <=j; ind++)
			{
				int coins = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1] + dp[ind+1][j]; 
				maxi = max(maxi,coins);
			}

			dp[i][j] = maxi;

		}
	}

	return dp[1][n];
}
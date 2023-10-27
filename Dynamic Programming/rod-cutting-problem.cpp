//MEMOIZATION TC:O(N*N) SC:O(N*N) + O(TARGET)
// #include<bits/stdc++.h>
// using namespace std;

// int solve(int ind, int n, vector<int>&price, vector<vector<int>>&dp)
// {
// 	if(ind == 0)
// 		return n*price[0];	//rodlength = 1

// 	if(dp[ind][n]!= -1)	return dp[ind][n];

// 	int skip = solve(ind-1,n,price,dp);
// 	int take = INT_MIN;
// 	int rodlen = ind + 1;
// 	if(rodlen<=n)	take = price[ind] + solve(ind,n-rodlen,price,dp);

// 	return dp[ind][n] = max(skip,take);
// }

// int cutRod(vector<int> &price, int n)
// {
// 	vector<vector<int>>dp(n,vector<int>(n+1,-1));
// 	return solve(n-1,n,price,dp);
// }

//TABULATION TC:O(N*N) SC:O(N*N)
// #include<bits/stdc++.h>
// using namespace std;

// int cutRod(vector<int> &price, int n)
// {
// 	vector<vector<int>>dp(n,vector<int>(n+1,0));
// 	for(int i =0; i<=n; i++)
// 	{
// 		dp[0][i] = i * price[0];
// 	}

// 	for(int ind = 1; ind<n; ind++)
// 	{
// 		for(int j = 0; j <=n; j++)
// 		{
// 			int skip = dp[ind-1][j];
// 			int take = INT_MIN;
// 			int rodlen = ind + 1;
// 			if(rodlen<=j)	take = price[ind] + dp[ind][j-rodlen];

// 			dp[ind][j] = max(skip,take);
// 		}
// 	}

// 	return dp[n-1][n];
// }

//SPACE OPTIMISATION	TC:O(N*N) SC:O(N) + O(N)
// #include<bits/stdc++.h>
// using namespace std;

// int cutRod(vector<int> &price, int n)
// {
// 	vector<int>prev(n+1,0),curr(n+1,0);
// 	for(int i =0; i<=n; i++)
// 	{
// 		prev[i] = i * price[0];
// 	}

// 	for(int ind = 1; ind<n; ind++)
// 	{
// 		for(int j = 0; j <=n; j++)
// 		{
// 			int skip = prev[j];
// 			int take = INT_MIN;
// 			int rodlen = ind + 1;
// 			if(rodlen<=j)	take = price[ind] + curr[j-rodlen];

// 			curr[j] = max(skip,take);
// 		}
// 		prev = curr;
// 	}

// 	return prev[n];
// }

//ULTIMATE SPACE OPTIMISATION 	TC:O(N*N) SC:O(N)
#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
	vector<int>curr(n+1,0);
	for(int i =0; i<=n; i++)
	{
		curr[i] = i * price[0];
	}

	for(int ind = 1; ind<n; ind++)
	{
		for(int j = 0; j <=n; j++)
		{
			int skip = curr[j];
			int take = INT_MIN;
			int rodlen = ind + 1;
			if(rodlen<=j)	take = price[ind] + curr[j-rodlen];

			curr[j] = max(skip,take);
		}
	}

	return curr[n];
}

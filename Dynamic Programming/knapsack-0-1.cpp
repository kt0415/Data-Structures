#include <bits/stdc++.h> 
using namespace std;

//MEMOIZATION   TC:O(N*W), SC:O(N*W)+O(N)..recursive stack space
// int solve(int idx, int wt, vector<int>&weight, vector<int>&value, int n, vector<vector<int>>&dp)
// {
// 	if(idx == 0)
// 	{
// 		if(weight[0]<=wt)	return value[0];
// 		else	return 0;	
// 	}

// 	if(dp[idx][wt]!= -1)	return dp[idx][wt];

// 	int notpick = solve(idx-1,wt,weight,value,n,dp);
// 	int pick = INT_MIN;
// 	if(weight[idx]<=wt)	pick = value[idx] + solve(idx-1,wt-weight[idx],weight,value,n,dp);

// 	return dp[idx][wt] = max(pick,notpick);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int W) 
// {
// 	vector<vector<int>>dp(n,vector<int>(W+1,-1));

// 	return solve(n-1,W,weight,value,n,dp);
// }

//TABULATION    TC:O(N*W), SC:O(N*W)
// #include <bits/stdc++.h> 
// using namespace std;

// int knapsack(vector<int> weight, vector<int> value, int n, int W) 
// {
// 	vector<vector<int>>dp(n,vector<int>(W+1,0));
// 	//base case
// 	for(int i=weight[0]; i<=W; i++)
// 	{
// 		dp[0][i] = value[0];
// 	}

// 	for(int ind = 1; ind <= n-1; ind++)
// 	{
// 		for(int wt = 0; wt <= W; wt++)
// 		{
// 			int notpick = dp[ind-1][wt];
// 			int pick = INT_MIN;

// 			if(weight[ind]<=wt)
// 				pick = value[ind] + dp[ind-1][wt-weight[ind]];

// 			dp[ind][wt] = max(notpick,pick);
// 		}
// 	}

// 	return dp[n-1][W];
// }

//SPACE OPTIMISATION TC:O(N*W), SC:O(W)+O(W)
// #include <bits/stdc++.h> 
// using namespace std;

// int knapsack(vector<int> weight, vector<int> value, int n, int W) 
// {
// 	vector<int>prev(W+1,0), curr(W+1,0);
// 	//base case
// 	for(int i=weight[0]; i<=W; i++)
// 	{
// 		prev[i] = value[0];
// 	}

// 	for(int ind = 1; ind <= n-1; ind++)
// 	{
// 		for(int wt = 0; wt <= W; wt++)
// 		{
// 			int notpick = prev[wt];
// 			int pick = INT_MIN;

// 			if(weight[ind]<=wt)
// 				pick = value[ind] + prev[wt-weight[ind]];

// 			curr[wt] = max(notpick,pick);
// 		}
// 		prev = curr;
// 	}

// 	return prev[W];
// }

//SINGLE ARRAY SPACE OPTIMISATION	TC:O(N*W), SC:O(W)
#include <bits/stdc++.h> 
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
	vector<int>prev(W+1,0);
	//base case
	for(int i=weight[0]; i<=W; i++)
	{
		prev[i] = value[0];
	}

	for(int ind = 1; ind <= n-1; ind++)
	{
		for(int wt = W; wt >=0; wt--)
		{
			int notpick = prev[wt];
			int pick = INT_MIN;

			if(weight[ind]<=wt)
				pick = value[ind] + prev[wt-weight[ind]];

			prev[wt] = max(notpick,pick);
		}
	}

	return prev[W];
}
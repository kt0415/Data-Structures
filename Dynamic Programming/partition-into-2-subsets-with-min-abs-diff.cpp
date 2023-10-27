#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum = 0;
	for(int i=0; i<n; i++)	totalsum += arr[i];

	int k = totalsum;
	//creation of the same dp array as in lec 14 so that to check for a given target k jitna sum wala subset present or not
	vector<vector<bool>>dp(n,vector<bool>(totalsum+1,false));

	for(int i=0; i<n; i++)	dp[i][0] = true;

	if(arr[0] <= k)
		dp[0][arr[0]] = true;

	for(int ind = 1; ind < n; ind++)
	{
		for(int target = 1; target < k; target++)
		{
			bool notpick = dp[ind-1][target];
			bool pick = false;
			if(arr[ind]<=target)	pick = dp[ind-1][target-arr[ind]];

			dp[ind][target] = pick | notpick;
		}
	}

	//the last row of our dp will tell if the specific value of S1 is possible or not aka true or false

	int mini = 1e9;

	for(int i=0; i<=totalsum/2; i++)
	{
		if(dp[n-1][i] == true)
		{
			int s1 = i;
			int s2 = totalsum - i;
			mini = min(mini, abs(s2-s1));
		}
	}

	return mini;
}

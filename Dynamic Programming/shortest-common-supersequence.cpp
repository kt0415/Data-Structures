#include <bits/stdc++.h> 
using namespace std;

string shortestSupersequence(string a, string b)
{
	int n = a.size();
	int m = b.size();

	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

	for(int i=0; i<=n; i++)	dp[i][0] = 0;
	for(int j=0; j<=m; j++)	dp[0][j] = 0;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];

			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	string ans = "";
	int i = n, j = m;
	while(i>0 && j>0)
	{
		if(a[i-1] == b[j-1])	//its a match!!
		{
			ans += a[i-1];
			i--;
			j--;
		}

		else if(dp[i-1][j]>dp[i][j-1])	//up value is more .. i will be exhausted
		{
			ans += a[i-1];
			i--;
		}

		else
		{
			ans += b[j-1];
			j--;
		}
	}

	//if some portion of s1 or s2 is remaining uske liye 2 while loop alag se
	while(i>0)	//if some portion of a was remaining
	{
		ans += a[i-1];
		i--;
	}

	while(j>0)	//if some portion of b was remaining
	{
		ans += b[j-1];
		j--;
	}

	//reverse the ans string at the end
	reverse(ans.begin(),ans.end());

	return ans;
}
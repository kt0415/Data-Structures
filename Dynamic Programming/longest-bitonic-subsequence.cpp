#include <bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) 
{
	vector<int>dp1(n,1),dp2(n,1);
    
    for(int ind=0; ind<n; ind++)
    {
        for(int prev=0; prev<ind; prev++)
        {
            if(arr[prev]<arr[ind] && dp1[prev] + 1 > dp1[ind])
                dp1[ind] = dp1[prev]+1;
        }
    }

	for(int ind=n-1; ind>=0; ind--)
    {
        for(int prev=n-1; prev>ind; prev--)
        {
            if(arr[prev]<arr[ind] && dp2[prev] + 1 > dp2[ind])
                dp2[ind] = dp2[prev]+1;
        }
    }
	   
	int maxi = 0;
	for(int i=0; i<n; i++)
	{
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}

	return maxi;
} 

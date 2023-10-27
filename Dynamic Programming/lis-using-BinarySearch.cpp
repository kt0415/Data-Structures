#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>v;
    v.push_back(arr[0]);

    for(int i=1; i<n; i++)
    {
        if(arr[i] > v.back())
        {
            v.push_back(arr[i]);
        }

        else
        {
            int idx = lower_bound(v.begin(),v.end(),arr[i]) - v.begin();
            v[idx] = arr[i];
        }
    }

    return v.size();
}

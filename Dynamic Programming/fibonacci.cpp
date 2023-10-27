#include <bits/stdc++.h>
using namespace std;


//memoization method
//TC: O(n) , SC: O(n)+O(n); //extra O(n) due to recursion stack space
int fibonacci(int n, vector<int>&dp)
{
    if(n <= 1)
        return n;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
}

//Tabulation Method
//TC: O(n), SC: O(n)
int fibotable(int n, vector<int>&dp)
{
    dp[0] = 0; dp[1] = 1;
    for(int i=2; i<n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main()
{
    int n; cin>>n;
    // vector<int>dp(n+1,-1);
    // cout<<fibonacci(n,dp)<<endl;
    // cout<<fibotable(n,dp)<<endl;

    //Most Optimised Approach without using Extra Space
    //TC: O(n), SC: O(1)
    int prev2 = 0;
    int prev = 1;

    for(int i=2; i<=n; i++)
    {
        int curr = prev2+prev;
        prev2 = prev;
        prev = curr;
    }

    cout<<prev<<endl;
    return 0;
}
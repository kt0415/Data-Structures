#include <bits/stdc++.h> 
long long int solve(vector<int> &nums)
{
    long long int n = nums.size();
    long long int prev = nums[0], prev2 = 0;
    for(int i=1; i<n; i++)
    {
        long long int take = nums[i];
        if(i>1) take += prev2;
        long long int skip = prev;
        long long int curr = max(take,skip);
        prev2 = prev;
        prev = curr; 
    }

    return prev;
}

long long int houseRobber(vector<int>& val)
{
    if(val.size() == 1)
        return val[0];

    vector<int>temp1,temp2;
    for(auto it: val)
    {
        temp1.push_back(it);
        temp2.push_back(it);
    }

    temp1.erase(temp1.begin());
    temp2.pop_back();

    long long int ans = max(solve(temp1),solve(temp2));

    return ans;
}
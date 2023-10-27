#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<int>>ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
    //base cases not needed as all initialised to zero

    //nested loops for changing parameters
    for(int ind = n-1; ind >= 0; ind --)
    {
        for(int buy = 0; buy < 2; buy ++)
        {
            for(int cap = k; cap > 0; cap --)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max((-prices[ind] + ahead[0][cap]),ahead[1][cap]);
                }

                else
                {
                    profit = max((prices[ind] +ahead[1][cap-1]),ahead[0][cap]);
                }

                curr[buy][cap] = profit;
            }
        }
        ahead = curr;
    }

    return ahead[1][k];
}

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isValid(vector<int>&piles, int h, int n, int hr)
    {
        int t = 0;
        for(int i=0; i<n; i++)
        {
            if(piles[i]%hr == 0)
                t += piles[i]/hr;
                
            else
                t += piles[i]/hr + 1;
        }
        
        if(t>h) return false;
        else    return true;
    }
  
    int Solve(int n, vector<int>& piles, int h) 
    {
        int low = 1; 
        int high = 0;
        
        for(int i=0; i<n; i++)
        {
            high = max(high,piles[i]);
        }
        
        int ans, res = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            
            if(isValid(piles,h,n,mid))
            {
                ans = mid;
                res = min(ans,res);
                high = mid - 1;
            }
            
            else
                low = mid + 1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
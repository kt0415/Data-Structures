//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isValid(int mid, vector<int>&bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        int total = 0, subarr = 0;
        
        for(int i=0; i<n; i++)
        {
            if(bloomDay[i]<=mid)
                total++;
            
            else
            {
                if(total>=k)    
                    subarr++;
                total = 0;
            }
            
            if(total>=k)
            {
                subarr++;
                total = 0;
            }
        }
        
        if(total>=k)
            subarr++;
        
        if(subarr>=m)
            return true;
        else
            return false;
    }
  
    int solve(int m, int k, vector<int> &bloomDay)
    {
        int n = bloomDay.size();
        if((long long)m*k>(long long)n)   return -1;
        
        int l = 1, r = *max_element(bloomDay.begin(),bloomDay.end());
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(isValid(mid,bloomDay,m,k))
                r = mid-1;
            else
                l = mid + 1;
        }
        
        return l;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends
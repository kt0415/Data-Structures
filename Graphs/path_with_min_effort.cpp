//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        
        set<pair<int,pair<int,int>>>s;
        vector<vector<int>>diff(n,vector<int>(m,1e9));
        diff[0][0] = 0;
        s.insert({0,{0,0}});
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!s.empty())
        {
            auto it = s.begin();
            s.erase(s.begin());
            int d = it->first;
            int row = it -> second.first;
            int col = it -> second.second;
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]),d);
                    if(newEffort<diff[nrow][ncol])
                    {
                        diff[nrow][ncol] = newEffort;
                        s.insert({newEffort, {nrow,ncol}});
                    }
                }
            }
        }
        
        int ans = diff[n-1][m-1];
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
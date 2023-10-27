//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));  //distance matrix to store all distances
        set<pair<int,pair<int,int>>>s;  //this stores the pair of distance and pair of row value and column value
        int src_row = source.first;
        int src_col = source.second;
        dist[src_row][src_col] = 0;
        s.insert({0,{src_row,src_col}});
        
        int dest_row = destination.first;
        int dest_col = destination.second;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!s.empty())
        {
            auto it = s.begin();
            s.erase(s.begin());
            int d = it -> first;
            int row = it -> second.first;
            int col = it -> second.second;
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == 1)
                {
                    if(d+1 < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = d + 1;
                        s.insert({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        
        int ans = dist[dest_row][dest_col];
        if(ans == 1e9)
            ans = -1;
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
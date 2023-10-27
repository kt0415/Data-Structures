//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //create graph
        vector<pair<int,int>>adj[n];    
        for(auto it: roads) //both ways .. bidirectional
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>dist(n,1e9); //0 based indexing, all elements initialised to infinity
        dist[0] = 0;    //except the source which is initialised to zero
        
        vector<int>ways(n,0);
        ways[0] = 1;
        
        set<pair<int,int>>s;    //pair of distance and node
        s.insert({0,0});
        int mod = (int)(1e9 + 7);
        while(!s.empty())
        {
            int d = s.begin() -> first;
            int node = s.begin() -> second;
            s.erase(s.begin());
            
            for(auto pr : adj[node])
            {
                int adjnode = pr.first;
                int wt = pr.second;
                
                if(d + wt < dist[adjnode])
                {
                    dist[adjnode] = d + wt;
                    s.insert({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                }
                
                else if(d + wt == dist[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        
        // if(ways[n-1] == 0)
        //     return -1;
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
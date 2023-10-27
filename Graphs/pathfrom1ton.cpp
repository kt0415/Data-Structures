//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //adjacency list creation
        vector<pair<int,int>>adj[n+1];    //+1 because of 1-based indexing
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        set<pair<int,int>>s;
        vector<int>dist(n+1,1e9);
        dist[1] = 0;
        
        vector<int>parent(n+1); //mark parent with themselves
        for(int i=0; i<n+1; i++)
        {
            parent[i] = i;  
        }
        
        s.insert({0,1});
        while(!s.empty())
        {
            auto it = s.begin();
            s.erase(s.begin());
            int node = it->second;
            int dis = it->first;
            
            for(auto pr: adj[node])
            {
                int wt = pr.second;
                int adjnode = pr.first;
                
                if(wt + dis < dist[adjnode])
                {
                    dist[adjnode] = wt+dis;
                    s.insert({dist[adjnode],adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        
        vector<int>ans;
        int node = n;
        while(parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size()==1)
        {
            ans.pop_back();
            ans.push_back(-1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

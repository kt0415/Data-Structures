#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfscheck(int node, vector<int>adj[], int vis[], int pathvis[], int Check[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        Check[node] = 0;
        
        //traversing for adjacent nodes
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfscheck(it,adj,vis,pathvis,Check)==true)
                {
                    Check[node] = 0;
                    return true;
                }
            }
            
            else if(vis[it] && pathvis[it])
            {
                Check[node] = 0;
                return true;
            }
        }
        
        Check[node] = 1;
        pathvis[node] = 0;
        return false;
    }    
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        int pathvis[V] = {0};
        vector<int>safe;
        int Check[V] = {0};
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfscheck(i,adj,vis,pathvis,Check);
            }
        }
        
        for(int i=0; i<V; i++)
        {
            if(Check[i]==1)
                safe.push_back(i);
        }
        
        return safe;
    }

    //BFS METHOD
    // vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    // {
    //     //BFS way...Topological Sort
    //     vector<int>adjrev[V];
    //     int indegree[V] = {0};
        
    //     for(int i =0; i<V; i++)
    //     {
    //         //i -> it of adjacency list to it -> i in reverse adjacency list   
    //         for(auto it: adj[i])
    //         {
    //             adjrev[it].push_back(i);
    //             indegree[i]++;
    //         }
    //     }
        
    //     queue<int>q;
    //     vector<int>safe;
        
    //     for(int i=0; i<V; i++)
    //     {
    //         if(indegree[i]==0)
    //             q.push(i);
    //     }
        
    //     while(!q.empty())
    //     {
    //         int node = q.front();
    //         q.pop();
    //         safe.push_back(node);
    //         for(auto it: adjrev[node])
    //         {
    //             indegree[it]--;
    //             if(indegree[it]==0)
    //             {
    //                 q.push(it);
    //             }
    //         }
    //     }

    //     sort(safe.begin(), safe.end());
    //     return safe;
    // }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

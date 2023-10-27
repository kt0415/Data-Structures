//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
private:
    vector<int>parent,size;

public:
    DisjointSet(int n)
    {//resizing our size and parent vectors to n+1 size in case of 1 based indexing and n size in case of 0 based indexing
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)    //to find the ultimate parent of the given node using path compression and recursion
    {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); //path compression done here
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u); //ultimate parent of u
        int pv = findParent(v); //ultimate parent of v

        if(pu == pv)    return; //if they have the same ultimate parent, dont do anything, simply return

        if(size[pu]<size[pv])   //if the pu's component is smaller than that of pv
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt,{node,adjnode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        
        int mstWt = 0;
        
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u)!=ds.findParent(v))
            {
                mstWt += wt; 
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

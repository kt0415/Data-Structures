//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
public:
    vector<int>parent,size;
    DisjointSet(int n)
    {//resizing our rank and parent vectors to n+1 size in case of 1 based indexing and n size in case of 0 based indexing
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


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) 
    {
        DisjointSet ds(n);
        int extra = 0;
        
        for(auto it: edge)
        {
            int u = it[0];
            int v = it[1];
            
            if(ds.findParent(u) == ds.findParent(v))    //if u and v have the same ultimate parent, it means they are already connected via him
                extra++;
                
            else
                ds.unionBySize(u,v);
        }
        
        int comp = 0;   //counting the components
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i] == i)
                comp++;
        }
        
        if(extra>=comp-1)
            return comp-1;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends